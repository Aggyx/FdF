/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:24:30 by smagniny          #+#    #+#             */
/*   Updated: 2022/12/12 16:38:01 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

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
}				t_mlx;

int		init(t_mlx *mlx);
char	**read_file(char *fname);
void	my_mlx_pixel_put(t_img *data, int x, int y);
void	my_mlx_pixel_putcolor(t_img *data, int x, int y, int color);
void	laferme(t_mlx *mlx);
#endif