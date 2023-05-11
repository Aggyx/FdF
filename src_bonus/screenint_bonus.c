/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenint_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:29:06 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/05 15:55:22 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils_bonus.h"

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
