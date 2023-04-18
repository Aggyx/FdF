/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:06:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/18 14:18:41 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	int	handle_input(int keypress, t_mlx *mlx)
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

// static	void	nxt_frame(t_mlx	*mlx)
// {
// 	//mlx_put_image_to_window(mlx.mlx, mlx->window, mlx->map->img, 0, 0);
// }

// static	void	frames_loop( t_mlx *mlx)
// {
// 	mlx_key_hook(mlx->mlx, handle_input, mlx);
// 	mlx_loop_hook(mlx->mlx, nxt_frame, mlx);
// 	mlx_loop(mlx->mlx);
// }

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
	mlx_put_image_to_window(mlx.mlx, mlx.window, map.img.img, 0, 0);
	mlx_key_hook(mlx.window, handle_input, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
