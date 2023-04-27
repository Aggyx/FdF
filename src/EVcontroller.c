/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EVcontroller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:35:43 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/27 17:51:41 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	int	handle_input(int keypress, t_mlx *mlx)
{
	if (keypress == 53)
		laferme(mlx);
	else if (keypress == 126)
	{
		mlx->map.zoom += 2;
		printf("Zooming +2...");
	}
	else if (keypress == 125)
	{
		mlx->map.zoom -= 2;
		printf("Zooming -2...");
	}
	else
		printf("Keypress:%d\n", keypress);
	rendermap(mlx);
	return (0);
}

void    EVcontroller(t_mlx  *mlx)
{
    mlx_hook(mlx->window, 17, 0, laferme, mlx);
    mlx_key_hook(mlx->window, handle_input, mlx);
}