/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EVcontroller_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:35:43 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/15 16:41:07 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils_bonus.h"

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
			*(unsigned int *)p = 0x00000000;
			j++;
		}
		i++;
	}
}

static	int	handle_input(int keypress, t_mlx *mlx)
{
	if (keypress == 53)
		laferme(mlx);
	else if (keypress == 109 || keypress == 46)
		mlx->map.zoom += 1;
	else if ((keypress == 110 && mlx->map.zoom > 1) || \
		(keypress == 45 && mlx->map.zoom > 1))
		mlx->map.zoom -= 1;
	else if (keypress == 65362 || keypress == 126)
		mlx->map.mv.yaxis -= 5;
	else if (keypress == 65364 || keypress == 125)
		mlx->map.mv.yaxis += 5;
	else if (keypress == 65363 || keypress == 124)
		mlx->map.mv.xaxis += 5;
	else if (keypress == 65361 || keypress == 123)
		mlx->map.mv.xaxis -= 5;
	else if (keypress == 108 || keypress == 37)
		mlx->map.mv.zaxis += 1;
	else if (keypress == 107 || keypress == 40)
		mlx->map.mv.zaxis -= 1;
	else
		printf("Keypress:%d\n", keypress);
	blscr(mlx);
	return (0);
}

void	evcontroller(t_mlx *mlx)
{
	mlx_hook(mlx->window, 17, 0, laferme, mlx);
	mlx_key_hook(mlx->window, handle_input, mlx);
}
