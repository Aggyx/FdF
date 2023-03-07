/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:41:59 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/07 14:36:45 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	my_mlx_pixel_putcolor(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	laferme(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
}

void	bresenham(t_point p1, t_point p2, t_mlx *mlx)
{
	float x_step;
	float y_step;
	int max;

	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y; 
	max = maxx(my_abs(x_step), my_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p1.x - p2.x) && (int)(p1.y - p2.y))
	{
		mlx_pixel_put(mlx->mlx, mlx->window, p1.x, p1.y, 0xffffff);
		p1.x += x_step;
		p1.y += y_step;
	}
}

void	rendermap(t_mlx *mlx)
{
	int		c;
	int		r;
	t_img	img;

	img.img = mlx_new_image(&img, 540, 440);
	img.addr = mlx_get_data_addr(&img, &img.bpp, &img.line_len, &img.endian);
	c = -1;
	r = 0;
	
	while ( ++c <= mlx->COLsizebuff && ++r <= mlx->LINEsizebuff)
		my_mlx_pixel_putcolor(&img, c, r, 0);
}