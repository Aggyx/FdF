/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:24:30 by smagniny          #+#    #+#             */
/*   Updated: 2023/02/05 17:28:29 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

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

typedef	struct	coord_struc
{
	char	**map;
	
}

int		init(t_mlx *mlx);
char	**read_file(char *fname);
void	my_mlx_pixel_putcolor(t_img *data, int x, int y, int color);
void	laferme(t_mlx *mlx);
int		merror(char *str, int errrnum);
int		handle_input(int keypress, t_mlx mlx);
#endif