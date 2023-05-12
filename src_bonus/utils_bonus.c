/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:34:02 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/11 19:00:51 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils_bonus.h"

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
	if (!tmp || !*tmp)
		return (0);
	while (tmp[i])
		i++;
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

void	panic(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}
