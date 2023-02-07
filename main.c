/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:06:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/02/05 17:32:04 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

/*
ESC : 53

open, close, read, write,
malloc, free, perror,
strerror, exit

*/

int	mlxmap(t_img map, t_mlx mlx)
{
	map.img = mlx_new_image(mlx.mlx, 980, 540);
	map.addr = mlx_get_data_addr(map.img, &map.bpp, &map.line_len, &map.endian);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	map;
	char	**buffer;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	if (!init(&mlx))
		return (0);
	buffer = read_file(argv[1]);
	mlxmap(&map, &mlx);
	
	while (i++ < 530)
		my_mlx_pixel_putcolor(&map, 10 + i, 270, 0xFFFFFF);


	mlx_put_image_to_window(mlx.mlx, mlx.window, map.img, 100, 50);
	mlx_key_hook(mlx.window, handle_input, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
