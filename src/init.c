/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:36:01 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/13 13:59:54 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	init(t_mlx *mlx, t_img	*img, t_map *map)
{
	(void)img;
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
	map->zoom = 4;
	map->center_x = (IMG_W / 2);
	map->center_y = (IMG_H / 2);
	return (1);
}
