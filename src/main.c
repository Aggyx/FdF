/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:06:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/03 16:20:52 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	handle_input(int keypress, t_mlx *mlx)
{
	if (keypress == 53)
	{
		free(mlx->mlx);
		laferme(mlx);
	}
	else
		printf("Keypress:%d\n", keypress);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	if (argc != 2)
		return (0);
	if (!init(&mlx, &map.img, &map))
		return (0);
	read_file(argv[1], &map);
	create_coords(&map);
	rendermap(&map, map.mapcor, &map.img);
	mlx_put_image_to_window(mlx.mlx, mlx.window, map.img.img, 5, 5);
	mlx_key_hook(mlx.window, handle_input, &mlx);
	mlx_loop(&mlx);
	return (0);
}
