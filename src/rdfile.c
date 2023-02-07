/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdfile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:44:35 by smagniny          #+#    #+#             */
/*   Updated: 2023/02/05 16:49:09 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	get_col(char *fname)
{
	int		f;
	char	c;
	int		i;

	i = 0;
	f = open(fname, O_RDONLY);
	if (f == -1)
		return (0);
	else
	{
		while (read(f, &c, 1) > 0)
		{
			if (c == '\n')
				break ;
			i++;
		}
	}
	close(f);
	return (i);
}

int	get_row(char *fname)
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
//	int		test = 0;
	i = -1;
	fd = open(fname, O_RDONLY);
	if (!fd)
		return (0);
	col = get_col(fname);
	row = get_row(fname);
	printf("Col:%d Row:%d\n", col,row);
	content = (char **)ft_calloc(row, sizeof(char **));
	while (++i < row)
		content[i] = ft_calloc(col, sizeof(char *));
	i = -1;
	while (++i < row)
		content[i] = get_next_line(fd);
/*
	while (row--)
	{
		printf("%s\n", content[test]);
		test++;
	}
*/
	return (content);
}
