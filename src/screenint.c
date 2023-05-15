/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:29:06 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/15 16:05:31 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	my_mlx_pixel_putcolor(t_img *img, t_point *p)
{
	char	*pixel;

	pixel = img->addr + (p->y * (img->line_len) + p->x * (img->bpp / 8));
	if (!p->color)
		p->color = 0xFFFFFF;
	*(unsigned int *)pixel++ = p->color;
}

int	laferme(t_mlx *mlx)
{
	int	r;

	r = mlx->map.lines;
	mlx_destroy_image(mlx->mlx, mlx->map.img.img);
	while (--r >= 0)
		free(mlx->map.mapcor[r]);
	free(mlx->map.mapcor);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
}

void	rendermap(t_mlx *mlx)
{
	int	r;
	int	c;

	r = -1;
	while (++r < mlx->map.lines)
	{
		c = -1;
		while (++c < mlx->map.col + 1)
		{
			if (c < mlx->map.col)
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
