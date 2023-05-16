/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:06:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/16 17:21:09 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	frames_loop(t_mlx *mlx)
{
	rendermap(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->map.img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		read_file(argv[1], &mlx.map);
		if (!init(&mlx, &mlx.map.img, &mlx.map))
			return (0);
		create_coords(&mlx.map);
		evcontroller(&mlx);
		mlx_loop_hook(mlx.mlx, frames_loop, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		ft_putendl_fd("Usage: ./FdF [file] \n	O_O", 2);
	return (0);
}
