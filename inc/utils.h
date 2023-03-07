/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:24:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/03/07 11:18:43 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_point
{
    int x;
    int y;
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

typedef struct mlx_struc
{
	void	*mlx;
	void	*window;
	char	**map;
	int		COLsizebuff;
	int		LINEsizebuff;
}				t_mlx;

int		init(t_mlx *mlx);
void	read_file(char *fname, t_mlx *mlx);
void	my_mlx_pixel_putcolor(t_img *data, int x, int y, int color);
void	laferme(t_mlx *mlx);
int 	my_abs(int x);
int		maxx(int a, int b);
void	bresenham(t_point p1, t_point p2, t_mlx *mlx);
void	rendermap(t_mlx	*mlx);
#endif