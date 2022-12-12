/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:06:30 by smagniny          #+#    #+#             */
/*   Updated: 2022/12/12 16:34:56 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/utils.h"

/*
ESC : 53
*/
int	handle_input(int keypress, t_mlx mlx)
{
	printf("Keypress:%d\n", keypress);
	if (keypress == 53)
	{
		free(mlx.mlx);
		laferme(&mlx);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	**buffer;

	if (argc != 2)
		return (0);
	if (!init(&mlx))
		return (0);
	buffer = read_file(argv[2]);
	printf("%s", buffer[1]);
	return (0);
}
