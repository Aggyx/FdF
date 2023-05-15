/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawrect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:44:26 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/15 18:50:39 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils_bonus.h"

static void	set_step(t_point *p, t_point *p1, t_bresenvalues *val)
{
	if (p1->x > p->x)
		val->x_step = 1;
	if (p1->x < p->x)
		val->x_step = -1;
	if (p1->y > p->y)
		val->y_step = 1;
	if (p1->y < p->y)
		val->y_step = -1;
}

void	bresenhamv2(t_point *p, t_point *p1, t_img *img)
{
	t_bresenvalues	val;

	val.dx = abs(p1->x - p->x);
	val.dy = abs(p1->y - p->y);
	set_step(p, p1, &val);
	val.error = val.dx - val.dy;
	while (p->x != p1->x || p->y != p1->y)
	{
		if (p->x >= 0 && p->x < IMG_W && p->y < IMG_H && p->y >= 0)
			my_mlx_pixel_putcolor(img, p);
		if (val.error > 0)
		{
			p->x += val.x_step;
			val.error -= val.dy;
		}
		else
		{
			p->y += val.y_step;
			val.error += val.dx;
		}
	}
}

static	void	draw_horrect(t_img *img)
{
	t_point	tpl;
	t_point	tpr;
	t_point	dwl;
	t_point	dwr;

	tpl.x = 9;
	tpl.y = 9;
	tpl.color = 0xFFFFFF;
	tpr.x = IMG_W - 9;
	tpr.y = 9;
	tpr.color = 0xFFFFFF;
	dwl.x = 10;
	dwl.y = IMG_H - 10;
	dwl.color = 0xFFFFFF;
	dwr.x = IMG_W - 10;
	dwr.y = IMG_H - 10;
	dwr.color = 0xFFFFFF;
	bresenhamv2(&tpl, &tpr, img);
	bresenhamv2(&dwl, &dwr, img);
}

static void	draw_vert_rect(t_img *img)
{
	t_point	tpl;
	t_point	tpr;
	t_point	dwl;
	t_point	dwr;

	tpl.x = 10;
	tpl.y = 10;
	tpl.color = 0xFFFFFF;
	tpr.x = IMG_W - 10;
	tpr.y = 10;
	tpr.color = 0xFFFFFF;
	dwl.x = 10;
	dwl.y = IMG_H - 10;
	dwl.color = 0xFFFFFF;
	dwr.x = IMG_W - 10;
	dwr.y = IMG_H - 10;
	dwr.color = 0xFFFFFF;
	bresenhamv2(&tpl, &dwl, img);
	bresenhamv2(&tpr, &dwr, img);
}

void	drawrect(t_mlx *mlx)
{
	draw_horrect(&mlx->map.img);
	draw_vert_rect(&mlx->map.img);
}
