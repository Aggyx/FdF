/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:36:01 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/22 16:09:49 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	init(t_mlx *mlx, t_map *map)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (-1);
	mlx->window = mlx_new_window(mlx->mlx, 980, 540, "FdF - Cartographie");
	if (mlx->window == NULL)
	{
		free(mlx->window);
		return (-1);
	}
	map->img = mlx_new_image(mlx->mlx, 980, 540);
	map->img->addr = mlx_get_data_addr(map->img, &map->img->bpp, \
		&map->img->line_len, &map->img->endian);
	map->zoom = 20;
	return (1);
}
