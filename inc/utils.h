/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:24:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/17 14:20:36 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
//"mlx/mlx.h"
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

# define IMG_H 540
# define IMG_W 980

typedef enum t_boolean
{
	False,
	True
}	t_bool;

typedef struct s_pointinf
{
	int	z;
	int	color;
}	t_pif;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct img_struc
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct t_imgmv
{
	int	xaxis;
	int	yaxis;
	int	zaxis;
}	t_mv;

typedef struct map_struct
{
	t_pif		**map;
	t_point		**mapcor;
	t_img		img;
	t_mv		mv;
	int			col;
	int			lines;
	int			zoom;
	int			resize;
	int			max_y;
	int			lowest_x;
	int			lowest_y;
	int			max_x;
}				t_map;

typedef struct mlx_struc
{
	void	*mlx;
	void	*window;
	t_map	map;
}				t_mlx;

typedef struct t_bresenval
{
	int	dx;
	int	dy;
	int	x_step;
	int	y_step;
	int	error;
}	t_bresenvalues;

//init
int		init(t_mlx *mlx, t_img	*img, t_map *map);
int		openfd(char *fname);
void	read_file(char *fname, t_map *map);
//render
void	create_coords(t_map *map);
t_point	*zoomproj(t_point *p, t_map *map);
void	bresenham(t_point *p, t_point *p1, t_img	*img);
void	rendermap(t_mlx *mlx);
void	resize(t_map *map);
void	blscr(t_mlx *mlx);
void	my_mlx_pixel_putcolor(t_img *img, t_point *p);
int		laferme(t_mlx *mlx);
void	evcontroller(t_mlx *mlx);
int		retrieve_color(char *tmp);
//auxiliaries
void	panic(char *str);
#endif