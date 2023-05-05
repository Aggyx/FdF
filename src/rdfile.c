/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdfile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:35 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/05 17:32:14 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	get_col(char *fname, int lines)
{
	int		f;
	int		t;
	int		col;
	char	**tmp;
	char	*raw;

	t = -1;
	col = 0;
	f = openfd(fname);
	while (lines--)
	{
		raw = get_next_line(f);
		tmp = ft_split(raw, ' ');
		free(raw);
		col = ft_len(tmp);
		doublefree(tmp);
		if (t != -1 && t != col)
		{	
			ft_printf("FdF: line %d: %dcols\n%d was expected\n", lines, col, t);
			return (0);
		}
		t = col;
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
	fd = openfd(fname);
	while (++j < map->lines)
	{
		i = -1;
		tmpp = get_next_line(fd);
		tmp = ft_split(tmpp, ' ');
		free(tmpp);
		if (!tmp)
			panic("FdF: Could not allocate memory.\n");
		while (++i < map->col && tmp[i])
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

	fd = openfd(fname);
	i = 0;
	close(fd);
	map->lines = get_row(fname);
	map->col = get_col(fname, map->lines);
	if (map->col == 0 || map->lines == 0)
		panic("FdF: Invalid map.\n");
	map->map = (t_pif **)ft_calloc(sizeof(t_pif **), map->lines);
	if (!map->map)
		panic("FdF: Could not allocate memory for map.");
	while (i < map->lines)
	{
		map->map[i] = (t_pif *)ft_calloc(sizeof(t_pif *), map->col);
		if (!map->map[i])
			panic("FdF: Could not allocate memory for map.");
		i++;
	}
	load(fname, map);
}
