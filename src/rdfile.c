/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdfile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:35 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/27 17:27:43 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	get_col(char *fname)
{
	int		f;
	int		i;
	int		col;
	char	**tmp;
	char	*raw;


	i = 0;
	col = 0;
	f = open(fname, O_RDONLY);
	if (f == -1)
		return (0);
	else
	{
		raw = get_next_line(f);
		tmp = ft_split(raw, ' ');
		while (tmp[i])
		{
			col += 1;
			++i;
		}
		free(raw);
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
			if (c == '\n' || c == '\0')
				line += 1;
			i++;
		}
	}
	close(f);
	return (line);
}

static int	retrieve_color(char *tmp)
{
	char	**parts;

	parts = ft_split(tmp, ',');
	if (ft_len(parts) <= 1)
		return (0);
	if (parts[1] && !ft_isnumber(parts[1], 16))
		return (0);
	return (ft_atoi_base(parts[1], 16));
}

static	void	load(char *fname, t_map *map)
{
	char	**tmp;
	char	*tmpp;
	int		fd;
	int		i;
	int		j;

	j = -1;
	fd = open(fname, O_RDONLY);
	while (++j < map->linesizebuff)
	{
		i = -1;
		tmpp = get_next_line(fd);
		if (!tmpp)
			panic("FdF: Could not allocate memory.\n");
		tmp = ft_split(tmpp, ' ');
		if (!tmp)
			panic("FdF: Could not allocate memory.\n");
		while (++i < map->colsizebuff && tmp[i])
		{
			map->map[j][i].z = ft_atoi(tmp[i]);
			map->map[j][i].color = retrieve_color(tmp[i]);
		}
		free(tmpp);
		doublefree(tmp);
	}
	printf("Raw loaded succesfully\n");
	close(fd);
}

void	read_file(char *fname, t_map *map)
{
	int	i;

	i = 0;
	map->colsizebuff = get_col(fname);
	map->linesizebuff = get_row(fname);
	ft_printf("Rows : %d\nCols : %d\n", map->linesizebuff, map->colsizebuff);
	map->map = (t_pointinfo **)ft_calloc(sizeof(t_pointinfo **), map->linesizebuff);
	if (!map->map) 
		panic("FdF: Could not allocate memory for map.");
	while (i < map->linesizebuff)
	{
		map->map[i] = (t_pointinfo *)ft_calloc(sizeof(t_pointinfo *), map->colsizebuff);
		if (!map->map[i])
			panic("FdF: Could not allocate memory for map.");
		i++;
	}
	load(fname, map);
}

