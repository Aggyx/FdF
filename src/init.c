/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:36:01 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/06 10:07:01 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (-1);
	mlx->window = mlx_new_window(mlx->mlx, 980, 540, "FdF - Cartographie");
	if (mlx->window == NULL)
	{
		free(mlx->window);
		return (-1);
	}
	return (1);
}