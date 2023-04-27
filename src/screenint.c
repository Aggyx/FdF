/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:29:06 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/27 17:31:47 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	my_mlx_pixel_putcolor(t_img *img, t_point *p)
{
	char	*pixel;
	int		i;

	p->color = 0xFF0000;
	//printf("(%d, %d) ", p->x, p->y);
	i = img->bpp - 8;
	pixel = img->addr + (p->y * (img->line_len) + p->x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (p->color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (p->color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	laferme(t_mlx *mlx)
{
	
	mlx_destroy_image(mlx->mlx, mlx->map.img.img);
	//free arraysssss
	exit(0);
}