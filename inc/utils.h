/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:24:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/12 14:21:23 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "limits.h" //  QUITA ESTA LIBRARIA LUEGO !!!
# include <fcntl.h>
# include <math.h>

# define IMG_H 540
# define IMG_W 980

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
	int		center_x;
	int		center_y;
}				t_map;

typedef struct mlx_struc
{
	void	*mlx;
	void	*window;
}				t_mlx;

int		init(t_mlx *mlx, t_img	*img, t_map *map);
void	read_file(char *fname, t_map *map);
void	create_coords(t_map *map);
void	limits(t_img *img);
void	my_mlx_pixel_putcolor(t_img *img, t_point *p, int color);
void	laferme(t_mlx *mlx);
int		my_abs(int x);
int		maxx(int a, int b);
void	rendermap(t_map *map, t_point **mapcor, t_img *img);
void 	bresenham(t_point p, t_point p1, t_img	*img);
void	zoom(t_point *p, t_map *map);
void	rotate(t_point *p);
void	free_arrays(t_point **point_array, int **int_array, int rows);
void	doublefree(char	**tmp);
void	panic(char *str);
#endif