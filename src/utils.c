/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:34:02 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/25 16:05:16 by smagniny         ###   ########.fr       */
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

int	ft_len(char **tmp)
{	
	int	i;
	i = 0;
	if (tmp[i])
	{
		while (tmp[i])
			i++;
	}
	return (i);
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