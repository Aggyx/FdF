/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:06:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/27 17:41:08 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (0);
	if (!init(&mlx, &mlx.map.img, &mlx.map))
		return (0);
	read_file(argv[1], &mlx.map);
	create_coords(&mlx.map);
	rendermap(&mlx);
	EVcontroller(&mlx);
	mlx_loop(mlx.mlx);
	// mlx_destroy_image(mlx.mlx, mlx.map.img.img);
	// mlx_destroy_window(mlx.mlx, mlx.window);
	return (0);
}
