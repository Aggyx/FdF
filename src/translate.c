/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:19:05 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/27 17:29:45 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	void	rotate(t_point *p)
{
	p->x = (p->x - p->y) * cos(0.52);
	p->y = ((p->x + p->y) * sin(0.52)) - p->z;
}

t_point	*zoomprojP(t_point *p, t_map *map)
{	
	t_point	*p1;
	
	p1 = (t_point *)ft_calloc(sizeof(t_point), 1);
	p1->x = p->x * map->zoom;
	p1->y = p->y * map->zoom;
	p1->z = p->z * map->zoom;
	rotate(p1);
	p1->x += ((IMG_W) / 2) - (((map->max_x - map->lowest_x) * map->zoom) / 2);
	p1->y += ((IMG_H) / 2) - (((map->max_y - map->lowest_y) * map->zoom)/ 2);
	if (map->resize)
	{
		p1->x *= map->resize;
		p1->y *= map->resize;
		p1->z *= map->resize;
	}
	return (p1);
}

static	void	apply_resize(t_map *map, float scalef)
{
	int	r;
	int	c;

	r = -1;
	while (++r < map->linesizebuff)
	{
		c = -1;
		while (++c < map->colsizebuff)
		{
			map->mapcor[r][c].x *= scalef;
			map->mapcor[r][c].y *= scalef;
			map->mapcor[r][c].z *= scalef;
		}
	}
}

float	resizecoef(t_map *map)
{
	int	inmax_x;
	int	inmax_y;
	int	dxmap;
	int	dymap;

	inmax_x = map->mapcor[0][map->colsizebuff - 1].x;
	dxmap = (inmax_x - map->mapcor[map->linesizebuff - 1][0].x);
	inmax_y = map->mapcor[map->linesizebuff - 1][map->colsizebuff - 1].y;
	dymap = (inmax_y - map->lowest_y);
	printf("size of rotmap; %d * %d \n", dxmap, dymap);
	if (dxmap > IMG_W || dxmap < 0)
		return (IMG_W / dxmap);
	else if (dymap > IMG_H || dymap < 0)
		return (IMG_H / dymap);
	return (0);
}

void	resize(t_map *map)
{
	float res = resizecoef(map);
	printf("scalef = %f\n", res);
	if (my_abs(res) > 0)
		apply_resize(map, my_abs(res));
}

void	shift(t_map *map, int lowest_y)
{
	int	r;
	int	c;
	int	inmax_y;
	int	inlow_x;
	int	inmax_x;

	r = -1;
	inmax_x = map->mapcor[0][map->colsizebuff - 1].x;
	inlow_x = map->mapcor[map->linesizebuff - 1][0].x;
	inmax_y = map->mapcor[map->linesizebuff - 1][map->colsizebuff - 1].y;
	while (++r < map->linesizebuff)
	{
		c = -1;
		while (++c < map->colsizebuff)
		{	
			map->mapcor[r][c].x +=	((IMG_W * map->zoom) / 2) - ((inmax_x - inlow_x) / 2);
			map->mapcor[r][c].y += ((IMG_H * map->zoom) / 2) - ((inmax_y - lowest_y) / 2);
			// printf("(%d, %d, %d) sur line %d, col %d\n , shift= X;%d Y;%d", map->mapcor[r][c].x, map->mapcor[r][c].y, map->mapcor[r][c].z, r, c, 
		}
	}
}