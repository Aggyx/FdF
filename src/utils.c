/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:34:02 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/12 12:35:32 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	my_abs(int x)
{	
	if (x > 0)
		return (x);
	else
		return (-x);
}

int	maxx(int a, int b)
{
	if (a > b)
		return (a);
	else if (b > a)
		return (b);
	else
		return (a);
}

void	doublefree(char	**tmp)
{
	int	i;

	i = 0;
	if (tmp != NULL)
	{
		while (tmp[i])
			free(tmp[i++]);
	}
	free(tmp);
}

void	free_arrays(t_point **point_array, int **int_array, int rows)
{	
	while (rows--)
	{
		free(point_array[rows]);
	}
	free(point_array);
	rows = rows + 1;
	while (rows--)
	{
		free(int_array[rows]);
	}
	free(int_array);
}

void	panic(char *str)
{
	perror(str);
	exit(0);
}

int	ft_strncmpers(char *s1, char *s2)
{
	if (*s1 == *s2)
		return (0);
	else
		return (1);
}

void	limits(t_img *img)
{
	t_point	p;

	p.x = 0;
	p.y = 0;
	while (p.y < IMG_H)
	{
		while (p.x < IMG_W)
		{
			my_mlx_pixel_putcolor(img, &p, 0xFF0000);
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
}