/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:19:05 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/09 14:44:37 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static	void	rotate(t_point *p)
{
	p->x = (p->x - p->y) * cos(0.523599);
	p->y = ((p->x + p->y) * sin(0.523599));
}

t_point	*zoomproj(t_point *p, t_map *map)
{	
	t_point	*p1;

	p1 = ft_calloc(sizeof(t_point), 1);
	p1->x = p->x * map->zoom; //* (map->col));
	p1->y = p->y * map->zoom; //* (map->lines));
	p1->z = p->z * map->zoom;
	p1->color = p->color;
	rotate(p1);
	p1->y -= p->z;
	p1->x += ((IMG_W) / 2) - ((map->col * map->zoom) / 2);
	p1->y += ((IMG_H) / 2) - ((map->lines * map->zoom) / 2);
	return (p1);
}
