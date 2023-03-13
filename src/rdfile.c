/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdfile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:35 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/08 03:41:43 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	get_col(char *fname)
{
	int		f;
	char	c;
	int		i;
	int		col;
	char	**tmp;

	i = 0;
	f = open(fname, O_RDONLY);
	if (f == -1)
		return (0);
	else
	{
		tmp = ft_split(get_next_line(f), ' ');
		while (tmp)
		{
			if (*tmp == ' ')
				++tmp;
			else
				col += 1;
			++tmp;
		}
	}
	doublefree(tmp);
	close(f);
	return (col);
}

static int	get_row(char *fname)
{
	int		f;
	char	c;
	int		i;
	int		line;

	i = 0;
	line = 0;
	f = open(fname, O_RDONLY);
	if (f == -1)
		return (0);
	else
	{
		while (read(f, &c, 1) > 0)
		{
			if (c == '\n')
			{
				line += 1;
			}
			i++;
		}
	}
	close(f);
	return (line);
}

char	*load(int fd)
{
	char	**tmp;
	int 	i;

	i = 0;
	tmp = ft_split(get_next_line(fd), ' ');
	while(tmp[i] != '\n')
	{
		if (tmp[i] >= '0' && tmp[i] <= '9')
			
	}
}


void	read_file(char *fname, t_mlx *mlx)
{
	int		i;
	int		fd;

	i = -1;
	fd = open(fname, O_RDONLY);
	mlx->colsizebuff = get_col(fname);
	mlx->linesizebuff = get_row(fname);
	mlx->map = (char **)ft_calloc(mlx->linesizebuff, sizeof(char **));
	while (++i < mlx->linesizebuff)
		mlx->map[i] = ft_calloc(mlx->colsizebuff, sizeof(char *));
	i = -1;
	while (++i < mlx->linesizebuff)
	{
		tmp = ft_split(get_next_line(fd), ' ');
		while()
		mlx->map[i] = ;
	}
	close(fd);
}
