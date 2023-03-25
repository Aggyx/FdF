/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:24:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/25 17:43:25 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
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
	char	**map;
	t_point	**mapcor;
	t_img	*img;
	int		colsizebuff;
	int		linesizebuff;
	int		zoom;
}				t_map;

typedef struct mlx_struc
{
	void	*mlx;
	void	*window;
<<<<<<< HEAD
	char	**map;
	int		colsizebuff;
	int		linesizebuff;
=======
>>>>>>> dev
}				t_mlx;

int		init(t_mlx *mlx, t_map *map);
void	read_file(char *fname, t_map *map);
void	create_coords(t_map *map);
void	my_mlx_pixel_putcolor(t_img *data, int x, int y, int color);
void	laferme(t_mlx *mlx);
int		my_abs(int x);
int		maxx(int a, int b);
<<<<<<< HEAD
void	bresenham(t_point p1, t_point p2, t_mlx *mlx);
void	rendermap(t_mlx	*mlx);
void	doublefree(char	**tmp);
=======
//void	bresenham(t_mlx *mlx, t_img *g);
void	bresenham(t_point p, t_point p1, t_map *map);
void	rendermap(t_map *map);
void	doublefree(char	**tmp);
void	panic(char *str);
>>>>>>> dev
#endif