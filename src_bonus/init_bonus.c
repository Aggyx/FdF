/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:36:01 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/16 22:48:34 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils_bonus.h"

int	openfd(char *fname)
{
	int	f;

	f = open(fname, O_RDONLY);
	if (f == -1)
		panic("FdF: Invalid file\n");
	return (f);
}

static void	init_norm(t_map *map)
{
	map->zoom = 1;
	map->mv.xaxis = 0;
	map->mv.yaxis = 0;
	map->mv.zaxis = 1;
	map->mv.project = 0;
	map->lowest_x = INT_MAX;
	map->lowest_y = INT_MAX;
	map->max_x = INT_MIN;
	map->max_y = INT_MIN;
}

int	init(t_mlx *mlx, t_img	*img, t_map *map)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		panic("Error: mlx_init()\n	X_X\n");
	mlx->window = mlx_new_window(mlx->mlx, IMG_W, IMG_H, "FdF - Cartographie");
	if (mlx->window == NULL)
	{
		panic("Error: mlx_new_window()\n	X_X\n");
		free(mlx->window);
		return (0);
	}
	img->img = mlx_new_image(mlx->mlx, IMG_W, IMG_H);
	if (!img->img)
	{
		panic("Error: mlx_new_image()\n    X_X\n");
		free(mlx->window);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
		&img->line_len, &img->endian);
	init_norm(map);
	return (1);
}
