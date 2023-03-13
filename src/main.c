/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:06:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/08 03:16:26 by smagniny         ###   ########.fr       */
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

	if (argc != 2)
		return (0);
	if (!init(&mlx))
		return (0);
	read_file(argv[1], &mlx);
	rendermap(&mlx);
	mlx_key_hook(mlx.window, handle_input, &mlx);
	mlx_loop(&mlx);
	return (0);
}
