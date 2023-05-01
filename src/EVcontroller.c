/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EVcontroller.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:35:43 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/01 14:38:16 by smagniny         ###   ########.fr       */
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
			p = mlx->map.img.addr + (i * mlx->map.img.line_len + j * (mlx->map.img.bpp / 8));
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
	else if (keypress == 109)
		mlx->map.zoom += 1;
	else if (keypress == 110 && mlx->map.zoom > 1)
		mlx->map.zoom -= 1;
	else if (keypress == 65362)
		mlx->map.mv.Yaxis -= 5;
	else if (keypress == 65364)
		mlx->map.mv.Yaxis += 5;
	else if (keypress == 65363)
		mlx->map.mv.Xaxis += 5;
	else if (keypress == 65361)
		mlx->map.mv.Xaxis -= 5;
	else if (keypress == 108)
		mlx->map.mv.Zaxis += 1;
	else if (keypress == 107)
		mlx->map.mv.Zaxis -= 1;
	else
		printf("Keypress:%d\n", keypress);
	blscr(mlx);
	drawrect(mlx);
	mlx_string_put(mlx->mlx, mlx->window, IMG_W - 100, 40, 0xFFFFFF,"- Key Binds -");
	rendermap(mlx);
	return (0);
}

void    EVcontroller(t_mlx  *mlx)
{
    mlx_hook(mlx->window, 17, 0, laferme, mlx);
    mlx_key_hook(mlx->window, handle_input, mlx);
}