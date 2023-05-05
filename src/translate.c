/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:19:05 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/05 17:45:56 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

float	resizecoef(t_map *map)
{
	int	inmax_x;
	int	inmax_y;
	int	dxmap;
	int	dymap;

	inmax_x = map->mapcor[0][map->col - 1].x;
	dxmap = (inmax_x - map->mapcor[map->lines - 1][0].x);
	inmax_y = map->mapcor[map->lines - 1][map->col - 1].y;
	dymap = (inmax_y - map->lowest_y);
	return (((IMG_W / 4) / dxmap));
}

static	void	rotate(t_point *p)
{
	p->x = (p->x - p->y) * cos(0.523599);
	p->y = ((p->x + p->y) * sin(0.523599));
}

t_point	*zoomproj(t_point *p, t_map *map)
{	
	t_point	*p1;

	p1 = ft_calloc(sizeof(t_point), 1);
	p1->x = p->x * map->zoom;
	p1->y = p->y * map->zoom;
	p1->z = p->z * map->zoom;
	p1->color = p->color;
	rotate(p1);
	p1->y -= p->z;
	p1->x += ((IMG_W) / 2) - ((map->col * map->zoom) / 2);
	p1->y += ((IMG_H) / 2) - ((map->lines * map->zoom) / 2);
	return (p1);
}
