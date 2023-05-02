/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxplus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:18:36 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/02 12:17:18 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

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
	printf("(960 / %d = %d -> %d / 20 = %d zoom)",(map->max_x - map->lowest_x), (IMG_W - 20) / (map->max_x - map->lowest_x), (IMG_W - 20) / (map->max_x - map->lowest_x), map->zoom);
	// if (resy < 0.1 || resx < 0.1)
	// {
	// 	map->zoom += 5;
	// 	printf("resize zoom applied \n zoom : %d", map->zoom);
	// }
}



void	create_coords(t_map *map)
{
	int		r;
	int		c;
	int		i;

	i = -1;
	r = 0;
	c = 0;
	map->mapcor = (t_point **)ft_calloc(sizeof(t_point *), map->linesizebuff);
	if (map->mapcor == NULL)
		panic("Error: ft_calloc mapcor");
	while (++i < map->linesizebuff)
	{
		map->mapcor[i] = (t_point *)ft_calloc(sizeof(t_point), \
		map->colsizebuff);
		if (map->mapcor[i] == NULL)
			panic("Error; ft_calloc mapcor[i]");
	}
	map->lowest_y = 2147483647;
	while (r < map->linesizebuff)
	{
		while (c < map->colsizebuff)
		{
			map->mapcor[r][c].x = c;
			map->mapcor[r][c].y = r;
			map->mapcor[r][c].z = map->map[r][c].z;
			map->mapcor[r][c].color = map->map[r][c].color;
			if (map->mapcor[r][c].y < map->lowest_y)
				map->lowest_y = map->mapcor[r][c].y;
			// printf("(%d, %d, %d) sur line %d, col %d\n", map->mapcor[r][c].x, map->mapcor[r][c].y, map->mapcor[r][c].z, r, c);
			c++;
		}
		free(map->map[r]);
		c = 0;
		r++;
	}
	resize(map);
	free(map->map);
}

void	bresenham(t_point *p, t_point *p1, t_img	*img)
{
	int	dx;
	int	dy;
	int x_step;
	int y_step;
	int error;

	dx = abs(p1->x - p->x);
	dy = abs(p1->y - p->y);
	if (p1->x > p->x)
		x_step = 1;
	else if (p1->x < p->x)
		x_step = -1;
	if (p1->y > p->y)
		y_step = 1;
	else if (p1->y < p->y)
		y_step = -1;
	error = dx - dy;
	while (p->x != p1->x || p->y != p1->y)
	{
		if (p->x >= 10 && p->x < IMG_W - 10 && p->y < IMG_H - 10 && p->y >= 10)
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

void	rendermap(t_mlx *mlx)
{
	int	r;
	int	c;

	r = -1;
	while (++r < mlx->map.linesizebuff)
	{
		c = -1;
		while (++c < mlx->map.colsizebuff)
		{
			if (c < mlx->map.colsizebuff - 1)
				bresenham(zoomprojP(&mlx->map.mapcor[r][c], &mlx->map), \
				zoomprojP(&mlx->map.mapcor[r][(c + 1)], &mlx->map), \
				&mlx->map.img);
			if (r < mlx->map.linesizebuff - 1)
				bresenham(zoomprojP(&mlx->map.mapcor[r][c], &mlx->map), \
				zoomprojP(&mlx->map.mapcor[(r + 1)][c], &mlx->map), \
				&mlx->map.img);
		}
	}
}



