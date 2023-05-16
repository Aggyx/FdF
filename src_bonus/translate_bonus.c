/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:19:05 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/16 22:54:11 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils_bonus.h"

static	void	rotate(t_point *p)
{
	p->x = (p->x - p->y) * cos(0.523599);
	p->y = ((p->x + p->y) * sin(0.523599));
}

static void	iso(t_point *p)
{
	double	vg;
	double	hg;
	int		x;
	int		y;
	int		z;

	vg = (35.264 * M_PI) / 180.0;
	hg = (45.0 * M_PI) / 180.0;
	x = p->x;
	y = p->y;
	z = p->z;
	p->x = (int)((x * cos(vg) - y * cos(hg) * sin(vg)) + 0.5);
	p->y = (int)((x * sin(vg) + y * cos(hg) * cos(vg) - z * sin(hg)) + 0.5);
	p->z = (int)((y * sin(hg) + z * cos(hg)) + 0.5);
}

t_point	*zoomproj(t_point *p, t_map *map)
{	
	t_point	*p1;

	p1 = (t_point *)ft_calloc(sizeof(t_point), 1);
	if (p1 == NULL)
		panic("FdF: Malloc Error");
	p1->x = p->x * map->zoom;
	p1->y = p->y * map->zoom;
	p1->z = p->z * map->zoom;
	p1->color = p->color;
	if (map->mv.project == 0)
		iso(p1);
	if (map->mv.project == 1)
	{	
		rotate(p1);
		p->y -= p->z * map->mv.zaxis;
	}
	p1->x += (((IMG_W) / 2) - (map->max_x - map->lowest_x / 2));
	p1->y += (((IMG_H) / 2) - (map->max_y - map->lowest_y / 2));
	p1->x += map->mv.xaxis;
	p1->y += map->mv.yaxis;
	return (p1);
}
