/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:19:05 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/16 12:35:26 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	void	rotate(t_point *p)
{
	p->x = (p->x - p->y) * cos(0.523599);
	p->y = ((p->x + p->y) * sin(0.523599)) - p->z;
}
/*
static void rotate(t_point* p)
{
    // Convert angles to radians
    double azimuth = 35.264 * M_PI / 180.0;
    double inclination = 45.0 * M_PI / 180.0;

    // Store initial coordinates
    int x = p->x;
    int y = p->y;
    int z = p->z;

    // Perform rotation in 3D space
    p->x = (int)((x * cos(azimuth) - y * cos(inclination) * sin(azimuth)) + 0.5);
    p->y = (int((x * sin(azimuth) + y * cos(inclination) * cos(azimuth) - z * sin(inclination)) + 0.5);
    p->z = (int)((y * sin(inclination) + z * cos(inclination)) + 0.5);
}
*/
t_point	*zoomproj(t_point *p, t_map *map)
{	
	t_point	*p1;

	p1 = malloc(sizeof(t_point) * 1);
	if (p1 == NULL)
		panic("FdF: Malloc Error");
	p1->x = p->x * map->zoom;
	p1->y = p->y * map->zoom;
	p1->z = p->z * map->zoom;
	p1->color = p->color;
	rotate(p1);
	p1->y -= p->z;
	p1->x += (((IMG_W) / 2) - (map->max_x - map->lowest_x / 2));
	p1->y += (((IMG_H) / 2) - (map->max_y - map->lowest_y / 2));
	return (p1);
}
