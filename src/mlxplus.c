/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxplus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:18:36 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/27 17:48:34 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	rst_img(t_img	*img)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < IMG_H)
	{
		while (++j < IMG_W)
		{
			char *pixel_addr = img->addr + (j * img->line_len) + (i * (img->bpp / 8));
			pixel_addr[0] = 0; // blue
			pixel_addr[1] = 0; // green
			pixel_addr[2] = 0; 
		}
	}
}

// // Loop over each pixel of the image
// for (int y = 0; y < height; y++) {
//     for (int x = 0; x < width; x++) {
//         // Get the address of the current pixel
//         char *pixel_addr = img.addr + (y * img.line_length) + (x * (img.bits_per_pixel / 8));

//         // Set the color values to zero (black)
//         pixel_addr[0] = 0; // blue
//         pixel_addr[1] = 0; // green
//         pixel_addr[2] = 0; // red
//     }
// }


void	rst_coords(t_map *map)
{
	int		r;
	int		c;

	r = 0;
	c = 0;
	while (r < map->linesizebuff)
	{
		while (c < map->colsizebuff)
		{
			map->mapcor[r][c].x = (c);
			map->mapcor[r][c].y = (r);
			map->mapcor[r][c].z = map->map[r][c].z;
			map->mapcor[r][c].color = map->map[r][c].color;
			c++;
		}
		c = 0;
		r++;
	}
	printf("Coords reseted\n");
}

void	create_coords(t_map *map)
{
	int		r;
	int		c;
	int		i;
	int		lowest_y;

	i = -1;
	r = 0;
	c = 0;
	map->mapcor = (t_point **)malloc(sizeof(t_point *) * map->linesizebuff);
	if (map->mapcor == NULL)
		panic("Malloc Error");
	while (++i < map->linesizebuff)
	{
		map->mapcor[i] = (t_point *)malloc(sizeof(t_point) * map->colsizebuff);
		if (map->mapcor[i] == NULL)
			panic("Malloc Error");
	}
	lowest_y = INT_MAX;
	while (r < map->linesizebuff)
	{
		while (c < map->colsizebuff)
		{
			map->mapcor[r][c].x = c;
			map->mapcor[r][c].y = r;
			map->mapcor[r][c].z = map->map[r][c].z;
			map->mapcor[r][c].color = 0xFF0000;
			// printf("(%d, %d, %d) sur line %d, col %d\n", map->mapcor[r][c].x, map->mapcor[r][c].y, map->mapcor[r][c].z, r, c);
			if (map->mapcor[r][c].y < lowest_y)
           		map->lowest_y = map->mapcor[r][c].y;
			c++;
		}
		c = 0;
		r++;
	}
	map->max_x = map->mapcor[0][map->colsizebuff - 1].x;
	map->lowest_x = map->mapcor[map->linesizebuff - 1][0].x;
	map->max_y = map->mapcor[map->linesizebuff - 1][map->colsizebuff - 1].y;
	if (resizecoef(map))
		map->resize = resizecoef(map);
	printf("\nCoords added succesfully and lowest y is %d.\n", map->lowest_y);
}

void	bresenham(t_point *p, t_point *p1, t_img	*img)
{
    int dx = abs(p1->x - p->x);
    int dy = abs(p1->y - p->y);

	int x_step = p1->x > p->x ? 1 : -1;
	int y_step = p1->y > p->y ? 1 : -1;
	int error = dx - dy;
	while (p->x != p1->x && p->y != p1->y)
	{
		if (p->x >= 0 && p->x < IMG_W && p->y < IMG_H && p->y >= 0)
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
	free(p1);
}

void	rendermap(t_mlx *mlx)
{
	int	r;
	int	c;

	r = -1;
	printf("\nlines: %d\n", mlx->map.linesizebuff);
	while (++r < mlx->map.linesizebuff)
	{
		c = -1;
		while (++c < mlx->map.colsizebuff)
		{
			if (c < mlx->map.colsizebuff - 1)
				bresenham(zoomprojP(&mlx->map.mapcor[r][c], &mlx->map), zoomprojP(&mlx->map.mapcor[r][(c + 1)], &mlx->map), &mlx->map.img);
			if (r < mlx->map.linesizebuff - 1)
				bresenham(zoomprojP(&mlx->map.mapcor[r][c], &mlx->map), zoomprojP(&mlx->map.mapcor[(r + 1)][c], &mlx->map), &mlx->map.img);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->map.img.img, 0, 0);
}

// void	rendermap(t_map *map, t_point **mapcor, t_img *img)
// {
// 	int	r;
// 	int	c;

// 	r = -1;
// 	while (++r < map->linesizebuff)
// 	{
// 		c = -1;
// 		while (++c < map->colsizebuff)
// 		{	
// 			if (c < map->colsizebuff - 1)
// 				bresenham(zoomprojP(&mapcor[r][c], map), zoomprojP(&mapcor[r][(c + 1)], map), img);
// 			if (r < map->linesizebuff - 1)
// 				bresenham(zoomprojP(&mapcor[r][c], map), zoomprojP(&mapcor[(r + 1)][c], map), img);
// 		}
// 	}
// }


