/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:36:01 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/27 15:54:13 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	init(t_mlx *mlx, t_img	*img, t_map *map)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (0);
	mlx->window = mlx_new_window(mlx->mlx, IMG_W, IMG_H, "FdF - Cartographie");
	if (mlx->window == NULL)
	{
		free(mlx->window);
		return (0);
	}
	img->img = mlx_new_image(mlx->mlx, IMG_W, IMG_H);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
		&img->line_len, &img->endian);
	map->zoom = 1;
	map->event = 0;
	map->lowest_y = 0;
	return (1);
}
