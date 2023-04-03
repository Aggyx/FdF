/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxplus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:41:59 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/03 16:37:49 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	my_mlx_pixel_putcolor(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	laferme(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
}

void	create_coords(t_map *map)
{
	int	r;
	int	c;
	int	i;

	i = -1;
	r = 0;
	c = 0;
	map->mapcor = (t_point **)malloc(sizeof(t_point **) * map->linesizebuff);
	if (map->mapcor == NULL)
		panic("Malloc Error");
	while (++i < map->linesizebuff)
		map->mapcor[i] = (t_point *)malloc(sizeof(t_point *) * map->colsizebuff);
	while (r < map->linesizebuff)
	{
		while (c < map->colsizebuff)
		{
			map->mapcor[r][c].x = c;
			map->mapcor[r][c].y = r;
			c++;
		}
		c = 0;
		r++;
	}
}

void	bresenham(t_point p, t_point p1, t_img	*img, t_map	*map)
{
	float	x_step;
	float	y_step;
	int		max;

	p.x *= map->zoom;
	p.y *= map->zoom;
	p1.x *= map->zoom;
	p1.y *= map->zoom;

	x_step = p1.x - p.x;
	y_step = p1.y - p.y;
	max = maxx(my_abs(x_step), my_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p.x - p1.x) || (int)(p.y - p1.y))
	{
		my_mlx_pixel_putcolor(img, p.x, p.y, 0xff0000);
		p.x += x_step;
		p.y += y_step;
	}
}

void	rendermap(t_map *map, t_point **mapcor, t_img *img)
{
	int	r;
	int	c;
	t_point p;
	t_point p1;
	t_point p2;

	(void)img;
	r = -1;
	while (++r < map->linesizebuff - 1)
	{
		c = -1;	
		while (++c < map->colsizebuff - 1)
		{
			p = mapcor[r][c];
			p1 = mapcor[r][c + 1];
			p2 = mapcor[r + 1][c];
			bresenham(p, p1, img, map);
			bresenham(p, p2, img, map);
		}
	}
	//bresenham(mapcor[0][0], mapcor[0][map->colsizebuff - 1], img, map);
	//bresenham(mapcor[map->linesizebuff - 1][0], mapcor[map->linesizebuff - 1][map->colsizebuff - 1], img, map);
}
