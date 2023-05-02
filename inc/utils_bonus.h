/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:24:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/02 12:47:05 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

# define IMG_H 540
# define IMG_W 980

typedef enum
{
	false,
	true
}	t_bool;

typedef struct s_pointinf
{
	int	z;
	int color;
}				t_pointinfo;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int color;
}				t_point;

typedef struct img_struc
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct t_imgmv
{
	int	Xaxis;
	int	Yaxis;
	int	Zaxis;
}		t_mv;

typedef struct map_struct
{
	t_pointinfo	**map;
	t_point	**mapcor;
	t_img	img;
	t_mv	mv;
	int		colsizebuff;
	int		linesizebuff;
	int		zoom;
	int		resize;
	int		max_y;
	int		lowest_x;
	int		lowest_y;
	int		max_x;
}				t_map;

typedef struct mlx_struc
{
	void	*mlx;
	void	*window;
	t_map	map;
}				t_mlx;

int		init(t_mlx *mlx, t_img	*img, t_map *map);
void	read_file(char *fname, t_map *map);
void	create_coords(t_map *map);
t_point	*zoomprojP(t_point *p, t_map *map);
void	shift(t_map *map, int lowest_y);
void	rendermap(t_mlx *mlx);
void	bresenham(t_point *p, t_point *p1, t_img	*img);
void	blscr(t_mlx *mlx);
void	my_mlx_pixel_putcolor(t_img *img, t_point *p);
int		laferme(t_mlx *mlx);
void	pixelput(t_img *img, int x, int y);
void    EVcontroller(t_mlx  *mlx);
void 	drawrect(t_mlx *mlx);
int		ft_len(char **tmp);
t_bool	ft_isnumber(char *str, int base);
int		ft_atoi_base(const char *str, int base);
int		my_abs(int x);
int		maxx(int a, int b);
void	doublefree(char	**tmp);
void	panic(char *str);
#endif