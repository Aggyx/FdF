/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:06:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/25 17:35:58 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

/*
ESC : 53
*/
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
	t_point	p;
	t_point	p1;

	p.x = 0;
	p.y = 0;

	p1.x = 100;
	p1.y = 100;

	if (argc != 2)
		return (0);
	if (!init(&mlx, &map))
		return (0);
	read_file(argv[1], &map);
	create_coords(&map);
//	rendermap(&mlx, &img);
	bresenham(p, p1, &map);
	mlx_put_image_to_window(mlx.mlx, mlx.window, map.img->img, 0, 0);
	mlx_key_hook(mlx.window, handle_input, &mlx);
	mlx_loop(&mlx);
	return (0);
}
