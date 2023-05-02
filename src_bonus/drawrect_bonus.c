/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawrect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 22:44:26 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/02 12:33:14 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils_bonus.h"

static	void	bresenhamv2(t_point *p, t_point *p1, t_img	*img)
{
    int dx = abs(p1->x - p->x);
    int dy = abs(p1->y - p->y);

	int x_step = p1->x > p->x ? 1 : -1;
	int y_step = p1->y > p->y ? 1 : -1;
	int error = dx - dy;
	while (p->x != p1->x || p->y != p1->y)
	{
		if (p->x >= 0 && p->x < IMG_W - 0 && p->y < IMG_H - 0 && p->y >= 0)
			my_mlx_pixel_putcolor(img, p);
		if (error > 0)
		{
			p->x += x_step;
			error -= dy;
		}
		else
		{
			p->y += y_step;
			error += dx;
		}
	}
	free(p);
	free(p1);
}

static  void	draw_horrect(t_img *img)
{
	t_point *tpL;
	t_point *tpR;
	t_point *dwL;
	t_point *dwR;

    tpL = ft_calloc(sizeof(t_point), 1);
	tpR = ft_calloc(sizeof(t_point), 1);
	dwL = ft_calloc(sizeof(t_point), 1);
	dwR = ft_calloc(sizeof(t_point), 1);
    tpL->x = 9;
	tpL->y = 9;
	tpL->color = 0xFFFFFF;
	tpR->x = IMG_W - 9;
	tpR->y = 9;
	tpR->color = 0xFFFFFF;
	dwL->x = 10;
	dwL->y = IMG_H - 10;
	dwL->color = 0xFFFFFF;
	dwR->x = IMG_W - 10;
	dwR->y = IMG_H - 10;
	dwR->color = 0xFFFFFF;
	bresenhamv2(tpL, tpR, img);
	bresenhamv2(dwL, dwR, img);
}

static void draw_vert_rect(t_img *img)
{
	t_point *tpL;
	t_point *tpR;
	t_point *dwL;
	t_point *dwR;

    tpL = ft_calloc(sizeof(t_point), 1);
	tpR = ft_calloc(sizeof(t_point), 1);
	dwL = ft_calloc(sizeof(t_point), 1);
	dwR = ft_calloc(sizeof(t_point), 1);
    tpL->x = 10;
	tpL->y = 10;
	tpL->color = 0xFFFFFF;
	tpR->x = IMG_W - 10;
	tpR->y = 10;
	tpR->color = 0xFFFFFF;
	dwL->x = 10;
	dwL->y = IMG_H - 10;
	dwL->color = 0xFFFFFF;
	dwR->x = IMG_W - 10;
	dwR->y = IMG_H - 10;
	dwR->color = 0xFFFFFF;
	bresenhamv2(tpL, dwL, img);
	bresenhamv2(tpR, dwR, img);
}

void drawrect(t_mlx *mlx)
{
    draw_horrect(&mlx->map.img);
    draw_vert_rect(&mlx->map.img);
}