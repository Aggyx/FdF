/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:06:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/01 14:32:55 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	frames_loop(t_mlx *mlx)
{
	//display frame before event
	drawrect(mlx);
	// mlx_string_put(mlx->mlx, mlx->window, IMG_W - 60, 30, 0x0a0a0a0a,"ESC - Exit");
	// mlx_string_put(mlx->mlx, mlx->window, IMG_W - 60, 45, 0x0a0a0a0a,"ARROW UP - Mouvement Up");
	// mlx_string_put(mlx->mlx, mlx->window, IMG_W - 60, 60, 0x0a0a0a0a,"ARROW DOWN - Mouvement Down");
	// mlx_string_put(mlx->mlx, mlx->window, IMG_W - 60, 75, 0x0a0a0a0a,"ARROW LEFT - Mouvement Left");
	// mlx_string_put(mlx->mlx, mlx->window, IMG_W - 60, 90, 0x0a0a0a0a,"ARROW RIGHT - Mouvement Right");
	// mlx_string_put(mlx->mlx, mlx->window, IMG_W - 60, 105, 0x0a0a0a0a,"M - Increment Zoom");
	// mlx_string_put(mlx->mlx, mlx->window, IMG_W - 60, 120, 0x0a0a0a0a,"N - Decrement Zoom");
	// mlx_string_put(mlx->mlx, mlx->window, IMG_W - 60, 135, 0x0a0a0a0a,"K/L - Depth value");
	rendermap(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->map.img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		if (!init(&mlx, &mlx.map.img, &mlx.map))
			return (0);
		read_file(argv[1], &mlx.map);
		create_coords(&mlx.map);
		EVcontroller(&mlx);
		mlx_string_put(mlx.mlx, mlx.window, IMG_W - 50, 15, 0xFFFFFF,"- Key Binds -");
		mlx_loop_hook(mlx.mlx, frames_loop, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		ft_putendl_fd("Usage: ./FdF [file] \n	O_O", 2);
	return (0);
}
