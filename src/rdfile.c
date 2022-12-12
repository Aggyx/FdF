/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdfile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:35 by smagniny          #+#    #+#             */
/*   Updated: 2022/12/12 18:32:34 by smagniny         ###   ########.fr       */
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

char	**read_file(char *fname)
{
	char	**content;
	int		col;
	int		row;
	int		i;
	int		fd;

	i = -1;
	fd = open(fname, O_RDONLY);
	col = get_col(fname);
	row = get_row(fname);
	content = (char **)ft_calloc(row, sizeof(char **));
	while (++i < row)
		content[i] = ft_calloc(col, sizeof(char *));
	i = -1;
	while (++i < row)
		content[i] = get_next_line(fd);
	return (content);
}