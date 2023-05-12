/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxplus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:18:36 by smagniny          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/09 16:15:15 by smagniny         ###   ########.fr       */
=======
/*   Updated: 2023/05/05 17:07:44 by smagniny         ###   ########.fr       */
>>>>>>> df60e2b5d723fef3e5da23361a4fbfaf1523e823
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

/*
void	resize(t_map *map)
{
	float	resx;
	float	resy;

	resx = 0;
	resy = 0;
	map->max_y = map->mapcor[0][0].y;
	map->max_x = map->mapcor[0][map->colsizebuff - 1].x;
	map->lowest_x = map->mapcor[map->linesizebuff - 1][0].x;
	resx = (map->max_x - map->lowest_x) / IMG_W;
	resy = (map->max_y - map->lowest_y) / IMG_H;
	map->zoom = (IMG_W - 20) / (map->max_x - map->lowest_x) / 3;
	printf("(960 / %d = %d -> %d / 20 = %d zoom)",(map->max_x - map->lowest_x),
			(IMG_W - 20) / (map->max_x - map->lowest_x), (IMG_W - 20)
			/ (map->max_x - map->lowest_x), map->zoom);
		if (resy < 0.1 || resx < 0.1)
		{
			map->zoom += 5;
 	printf("resize zoom applied \n zoom : %d", map->zoom);
		}
}
*/

static void	init_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

void	create_coords(t_map *map)
{
	int	c;
	int	i;

	i = -1;
	c = -1;
	map->lowest_y = INT_MAX;
	map->mapcor = (t_point **)ft_calloc(sizeof(t_point *), map->lines);
	if (map->mapcor == NULL)
		panic("Error: ft_calloc mapcor");
	while (++i < map->lines)
	{
		map->mapcor[i] = (t_point *)ft_calloc(sizeof(t_point), map->col);
		if (map->mapcor[i] == NULL)
			panic("Error; ft_calloc mapcor[i]");
		while (++c < map->col)
		{
			init_point(&map->mapcor[i][c], c, i, map->map[i][c].z);
			map->mapcor[i][c].color = map->map[i][c].color;
			if (map->mapcor[i][c].y < map->lowest_y)
				map->lowest_y = map->mapcor[i][c].y;
		}
		c = -1;
		free(map->map[i]);
	}
	free(map->map);
}

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

void	bresenham(t_point *p, t_point *p1, t_img *img)
{
	t_bresenvalues	*val;

	val = ft_calloc(sizeof(t_bresenvalues), 1);
	val->dx = abs(p1->x - p->x);
	val->dy = abs(p1->y - p->y);
	set_step(p, p1, val);
	val->error = val->dx - val->dy;
	while (p->x != p1->x || p->y != p1->y)
	{
		if (p->x >= 10 && p->x < IMG_W - 10 && p->y < IMG_H - 10 && p->y >= 10)
			my_mlx_pixel_putcolor(img, p);
		if (val->error > 0)
		{
			p->x += val->x_step;
			val->error -= val->dy;
		}
		else
		{
			p->y += val->y_step;
			val->error += val->dx;
		}
	}
	free(val);
	free(p);
	free(p1);
}

void	rendermap(t_mlx *mlx)
{
	int	r;
	int	c;

	r = -1;
	while (++r < mlx->map.lines)
	{
		c = -1;
		while (++c < mlx->map.col)
		{
			if (c < mlx->map.col - 1)
				bresenham(zoomproj(&mlx->map.mapcor[r][c], &mlx->map), \
							zoomproj(&mlx->map.mapcor[r][(c + 1)], &mlx->map), \
							&mlx->map.img);
			if (r < mlx->map.lines - 1)
				bresenham(zoomproj(&mlx->map.mapcor[r][c], &mlx->map), \
							zoomproj(&mlx->map.mapcor[(r + 1)][c], &mlx->map), \
							&mlx->map.img);
		}
	}
}
