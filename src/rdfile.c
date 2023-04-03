/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdfile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:35 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/03 12:55:01 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	get_col(char *fname)
{
	int		f;
	int		i;
	int		col;
	char	**tmp;

	i = 0;
	col = 0;
	f = open(fname, O_RDONLY);
	if (f == -1)
		return (0);
	else
	{
		tmp = ft_split(get_next_line(f), ' ');
		while (tmp[i])
		{
			col += 1;
			++i;
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

static	void	load(char *fname, t_map *map)
{
	char	**tmp;
	int		fd;
	int		i;
	int		j;
	int		k;

	j = -1;
	k = -1;
	fd = open(fname, O_RDONLY);
	while (++j < map->linesizebuff)
	{	
		i = -1;
		tmp = ft_split(get_next_line(fd), ' ');
		while ((int)tmp[++i] != '\n' && i < map->colsizebuff)
		{	
			while (tmp[i][++k])
			{
				if (tmp[i][k] < '0' && tmp[i][k] > '9')
					panic("ERROR: Bad map file !");
			}
			map->map[j][i] = ft_atoi(tmp[i]);
		}
	}
	close(fd);
}

void	read_file(char *fname, t_map *map)
{
	int		i;

	i = -1;
	map->colsizebuff = get_col(fname);
	map->linesizebuff = get_row(fname);
	ft_printf("Rows : %d\nCols : %d\n", map->linesizebuff, map->colsizebuff);
	map->map = (int **)ft_calloc(map->linesizebuff, sizeof(int **));
	while (++i < map->linesizebuff)
		map->map[i] = (int *)ft_calloc(map->colsizebuff, sizeof(int *));
	load(fname, map);
}
