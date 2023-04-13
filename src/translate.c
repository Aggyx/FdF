/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:19:05 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/13 15:38:27 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	zoom(t_point *p, t_map *map)
{
	//p->x += IMG_W / 4;//map->center_x / 2;
	//p->y += IMG_H / 4;//map->center_y / 2;
	p->x *= map->zoom;
	p->y *= map->zoom;
}

void	rotate(t_point *p)
{
	p->x = (p->x - p->y) * cos(0.513);
	p->y = (p->x + p->y) * sin(0.513) - p->z;
}
// void	matrixmult(t_point **mapcor, t_point **ref, t_map *map)
// {
// 	// for (int i = 0; i < N; i++) {
//     //     for (int j = 0; j < P; j++) {
//     //         C[i][j] = 0;
//     //         for (int k = 0; k < M; k++) {
//     //             C[i][j] += A[i][k] * B[k][j];
//     //         }
//     //     }
//     // }
// 	t_point	**transcord;  
// 	int		r;
// 	int		i;
// 	int		c;

// 	transcord = ft_calloc(sizeof(t_point **), map->linesizebuff);
// 	if (transcord)
// 		while (transcord[i++])
// 			transcord = ft_calloc(sizeof(t_point *), map->colsizebuff);
// 	whil
// }

// def multiply_m(a, b):
//      a_rows - len(a)
//      a_cols - 1en(a[@])
//     b_rows - len(b)
//     b_cols - len(b[o))
//      E Dut product natrix dimentions e a_rows . b_cola
//     product - I ١٤٥ for_in range(b_cols)] for_in range(a_rows)]
//      if a_cols .. b_rows
//          for i in range(a_rows):
//              for i in range(b_cols):
//                  for k in range(b_rows):
//                     product[i][5] .. o[i][k] * ([[]](5)
//     else:
//         print("INCOPPATIBLE MATRIX SIZES")
//      return product

