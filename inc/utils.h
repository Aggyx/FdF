/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:24:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/03 16:39:23 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct img_struc
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct map_struct
{
	int		**map;
	t_point	**mapcor;
	t_img	img;
	int		colsizebuff;
	int		linesizebuff;
	int		zoom;
}				t_map;

typedef struct mlx_struc
{
	void	*mlx;
	void	*window;
}				t_mlx;

int		init(t_mlx *mlx, t_img	*img, t_map *map);
void	read_file(char *fname, t_map *map);
void	create_coords(t_map *map);
void	my_mlx_pixel_putcolor(t_img *img, int x, int y, int color);
void	laferme(t_mlx *mlx);
int		my_abs(int x);
int		maxx(int a, int b);
void	bresenham(t_point p, t_point p1, t_img	*img, t_map	*map);
void	rendermap(t_map *map, t_point **mapcor, t_img *img);
void	doublefree(char	**tmp);
void	panic(char *str);
#endif