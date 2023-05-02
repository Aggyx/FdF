/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdfile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:35 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/02 12:33:32 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils_bonus.h"

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
		free(raw);
		while (tmp[i])
		{
			col += 1;
			++i;
		}
		doublefree(tmp);
	}
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
	int		res;

	parts = ft_split(tmp, ',');
	if (ft_len(parts) <= 1)
	{
		doublefree(parts);
		return (0xFFFFFFFF);
	}
	else if (parts[1] && !ft_isnumber(parts[1], 16))
	{
		doublefree(parts);
		return (0xFFFFFFFF);
	}
	res = ft_atoi_base(parts[1], 16);
	doublefree(parts);
	return (res);
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
	if (fd == -1)
		panic("FdF: Could not open file.\n");
	while (++j < map->linesizebuff)
	{
		i = -1;
		tmpp = get_next_line(fd);
		if (!tmpp)
			panic("FdF: Could not allocate memory.\n");
		tmp = ft_split(tmpp, ' ');
		free(tmpp);
		if (!tmp)
			panic("FdF: Could not allocate memory.\n");
		while (++i < map->colsizebuff && tmp[i])
		{
			map->map[j][i].z = ft_atoi(tmp[i]);
			map->map[j][i].color = retrieve_color(tmp[i]);
		}
		doublefree(tmp);
	}
	close(fd);
}

void	read_file(char *fname, t_map *map)
{
	int	i;
	int	fd;

    fd = open(fname, O_RDONLY);
	i = 0;
	if (!fd)
		panic("FdF: Could not open file.\n");
	close(fd);
	map->colsizebuff = get_col(fname);
	map->linesizebuff = get_row(fname);
	if (map->colsizebuff == 0 || map->linesizebuff == 0)
		panic("FdF: Nothing in file.\n");
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


