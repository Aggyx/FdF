/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:06:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/07 15:01:17 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

/*
ESC : 53
*/
int	handle_input(int keypress, t_mlx *mlx)
{
	printf("Keypress:%d\n", keypress);
	if (keypress == 53)
	{
		free(mlx->mlx);
		laferme(mlx);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_point	p;
	t_point p1;

	if (argc != 2)
		return (0);
	if (!init(&mlx))
		return (0);
	read_file(argv[1], &mlx);
	p.x = 10;
	p.y = 10;
	p1.x = 250;
	p1.y = 250;
	bresenham(p, p1, &mlx);
	mlx_key_hook(mlx.window, handle_input, &mlx);
	mlx_loop(&mlx);
	return (0);
}

