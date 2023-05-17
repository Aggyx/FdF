/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:19:05 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/17 14:38:54 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils_bonus.h"

static int	resize_norm(t_map *map, int dx, int dy, int z)
{
	int	tmp;

	tmp = dx;
	printf("X difference: %d\n", dx);
	while (((float)dx / (float)(IMG_W - 20)) < 0.3)
	{
		dx = tmp;
		z++;
		dx *= z;
	}
	printf("	zoom final for window dx: %d\n", z);
	map->zoom = z;
	tmp = dy;
	z = 1;
	printf("Y difference: %d\n", dy);
	while (((float)dy / (float)(IMG_H - 20)) < 0.3)
	{
		dy = tmp;
		z++;
		dy *= z;
	}
	printf("	zoom final for window dy: %d\n", z);
	return (fmin(map->zoom, z));
}

void	resize(t_map *map)
{
	int		z;
	int		dx;
	int		dy;

	z = 1;
	map->max_x = map->mapcor[0][map->col].x;
	map->lowest_x = map->mapcor[map->lines - 1][0].x;
	map->max_y = map->mapcor[map->lines - 1][map->col].y;
	map->lowest_y = map->mapcor[0][0].y;
	dx = map->max_x - map->lowest_x;
	dy = map->max_y - map->lowest_y;
	printf("-----resize-----\n");
	map->zoom = resize_norm(map, dx, dy, z);
	printf("ZOOM; %d\n", map->zoom);
}

static	void	rotate(t_point *p)
{
	p->x = (p->x - p->y) * cos(0.523599);
	p->y = ((p->x + p->y) * sin(0.523599));
}

static void	iso(t_point *p, t_map *map)
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
	p->y = (int)((x * sin(vg) + y * cos(hg) * cos(vg) \
		- (z * map->mv.zaxis) * sin(hg)) + 0.5);
	p->z = (int)((y * sin(hg) + (z * map->mv.zaxis) * cos(hg)) + 0.5);
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
		iso(p1, map);
	if (map->mv.project == 1)
	{	
		rotate(p1);
		p1->y -= (int)((float)p1->z * map->mv.zaxis);
	}
	p1->x += (((IMG_W) / 2) - (map->max_x - map->lowest_x / 2));
	p1->y += (((IMG_H) / 2) - (map->max_y - map->lowest_y / 2));
	p1->x += map->mv.xaxis;
	p1->y += map->mv.yaxis;
	return (p1);
}
