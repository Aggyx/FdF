/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdfile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:35 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/07 11:19:59 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"


static int	get_col(char *fname)
{
	int		f;
	char	c;
	int		i;
	int		line;

	i = 0;
	f = open(fname, O_RDONLY);
	if (f == -1)
		return (0);
	else
	{
		while (read(f, &c, 1) > 0)
		{
			if (c == '\n')
			{
				line = i;
			}
			i++;
		}
	}
	close(f);
	return (line);
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

void	read_file(char *fname, t_mlx *mlx)
{
	int		i;
	int		fd;

	i = -1;
	fd = open(fname, O_RDONLY);
	mlx->COLsizebuff = get_col(fname);
	mlx->LINEsizebuff = get_row(fname);
	mlx->map = (char **)ft_calloc(mlx->LINEsizebuff, sizeof(char **));
	while (++i < mlx->COLsizebuff)
		mlx->map[i] = ft_calloc(mlx->COLsizebuff, sizeof(char *));
	i = -1;
	while (++i < mlx->COLsizebuff)
		mlx->map[i] = get_next_line(fd);
}