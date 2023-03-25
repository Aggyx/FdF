/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdfile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:35 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/25 17:36:12 by smagniny         ###   ########.fr       */
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

<<<<<<< HEAD
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
=======
static	void	load(char *fname, t_map *map)
>>>>>>> dev
{
	char	**tmp;
	int		fd;
	int		i;
	int		j;
	int		k;

	j = -1;
	k = -1;
	fd = open(fname, O_RDONLY);
<<<<<<< HEAD
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
=======
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
	map->colsizebuff = get_col(fname) - 1;
	map->linesizebuff = get_row(fname) - 1;
	ft_printf("Rows : %d\nCols : %d\n", map->linesizebuff, map->colsizebuff);
	map->map = (char **)ft_calloc(map->linesizebuff, sizeof(char **));
	while (++i < map->linesizebuff)
		map->map[i] = ft_calloc(map->colsizebuff, sizeof(char));
	load(fname, map);
>>>>>>> dev
}
