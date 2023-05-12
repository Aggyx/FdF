/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EVcontroller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:35:43 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/11 19:01:07 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	blscr(t_mlx *mlx)
{
	int		i;
	char	*p;
	int		j;

	if (!mlx->map.img.img)
		return ;
	i = 9;
	while (i < IMG_H - 10)
	{
		j = 9;
		while (j < IMG_W - 10)
		{
			p = mlx->map.img.addr + \
				(i * mlx->map.img.line_len + j * (mlx->map.img.bpp / 8));
			*(unsigned int *)p = 0x000000;
			j++;
		}
		i++;
	}
}

static	int	handle_input(int keypress, t_mlx *mlx)
{
	if (keypress == 53)
		laferme(mlx);
	blscr(mlx);
	rendermap(mlx);
	return (0);
}

void	evcontroller(t_mlx *mlx)
{
	mlx_hook(mlx->window, 17, 0, laferme, mlx);
	mlx_key_hook(mlx->window, handle_input, mlx);
}
