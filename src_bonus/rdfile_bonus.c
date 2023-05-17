/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdfile_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:35 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/17 12:45:52 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils_bonus.h"

static int	get_col_norm(int f)
{
	char	*r;
	int		col;
	int		i;

	i = 0;
	col = 0;
	r = get_next_line(f);
	while (r[i] && r[i] != '\n')
	{
		while (r[i] && r[i] == ' ' && r[i] != '\n')
			i++;
		while (r[i] && r[i] != ' ' && r[i] != '\n')
		{
			if ((r[i] <= 0 || r[i] >= 9) && (r[i] != ',') && \
				(r[i] <= 'a' && r[i] >= 'f') && (r[i] <= 'A' && r[i] >= 'F'))
				return (-1);
			i++;
		}
		if (r[i] && r[i] == '\n')
			break ;
		col++;
		i++;
	}
	free(r);
	return (col);
}

static int	get_col(char *fname, int lines)
{
	int		f;
	int		t;
	int		col;

	t = -1;
	col = 0;
	f = openfd(fname);
	while (lines--)
	{
		col = get_col_norm(f);
		if (t != -1 && t != col)
			printf("line %d has %dcols\n", lines, col);
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
	c = 1;
	line = 0;
	f = openfd(fname);
	while (read(f, &c, 1) > 0)
	{
		if (c == '\n' || c == '\0')
			line += 1;
		else if (c < 0)
			panic("FdF: Invalid file");
		i++;
	}
	close(f);
	return (line);
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
		tmp = ssplit(tmpp, ' ');
		free(tmpp);
		if (!tmp)
			panic("FdF: Could not allocate memory.\n");
		while (++i <= map->col && tmp[i] != NULL)
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
		panic("FdF: Nothing in file.\n");
	map->map = (t_pif **)ft_calloc(sizeof(t_pif **), map->lines);
	if (map->map == NULL)
		panic("FdF: Could not allocate memory for map.");
	while (i < map->lines)
	{	
		map->map[i] = (t_pif *)ft_calloc(sizeof(t_pif *), map->col + 1);
		if (!map->map[i])
			panic("FdF: Could not allocate memory for map.");
		i++;
	}
	load(fname, map);
}
