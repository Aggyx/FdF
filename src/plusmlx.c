/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plusmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:12:48 by smagniny          #+#    #+#             */
/*   Updated: 2023/02/04 21:06:02 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		merror("MLX init failed", -1);
	mlx->window = mlx_new_window(mlx->mlx, 980, 540, "FdF - Cartographie");
	if (mlx->window == NULL)
	{
		free(mlx->window);
		return (-1);
	}
	return (1);
}

void	laferme(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
}

void	my_mlx_pixel_putcolor(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}