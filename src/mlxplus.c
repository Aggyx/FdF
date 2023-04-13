/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxplus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:18:36 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/13 15:41:10 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

/*To resize the map or image to fit within the window, you can first calculate the maximum and minimum values of the x and y coordinates in your 2D array of t_points. This will give you the extent of your map.

Next, you can calculate the width and height of the map by taking the difference between the maximum and minimum values of the x and y coordinates. If the width or height of the map is larger than the width or height of the window, you will need to scale it down.

To scale the map, you can calculate the scaling factor as the ratio between the size of the window and the size of the map. For example, if the window is 800 pixels wide and the map is 1200 pixels wide, the scaling factor would be 800 / 1200 = 0.6667.

Once you have calculated the scaling factor, you can multiply the x and y coordinates of each point in your 2D array by the scaling factor to scale the map down. Finally, you can apply the isometric transformation to the scaled map.

If the resulting map is still larger than the size of the window, you can repeat the process by further scaling it down until it fits. Alternatively, you could consider adding scrollbars or allowing the user to pan the map to view different parts of it.*/


// static	void	apply_rot(t_map *map)
// {
// 	int	r;
// 	int	c;

// 	r = -1;
// 	while (++r < map->linesizebuff)
// 	{
// 		c = -1;
// 		while (++c < map->colsizebuff)
// 			rotate(&map->mapcor[r][c]);
// 	}
// }

// static	void	apply_resize(t_map *map)
// {
// 	int	r;
// 	int	c;

// 	r = -1;
// 	while (++r < map->linesizebuff)
// 	{
// 		c = -1;
// 		while (++c < map->colsizebuff)
// 		{
// 			map->mapcor[r][c].x *= map->zoom;
// 			map->mapcor[r][c].y *= map->zoom;
// 		}
// 	}
// }

// static	void	apply_resize(t_map *map, float scalef)
// {
// 	int	r;
// 	int	c;

// 	r = -1;
// 	while (++r < map->linesizebuff)
// 	{
// 		c = -1;
// 		while (++c < map->colsizebuff)
// 		{
// 			map->mapcor[r][c].x *= scalef;
// 			map->mapcor[r][c].y *= scalef;
// 			map->mapcor[r][c].z *= scalef;
// 		}
// 	}
// }

// static	float	resize(t_map *map, int lowest_y)
// {
// 	int	inmax_x;
// 	int	inmax_y;
// 	int	dxmap;
// 	int	dymap;

// 	inmax_x = map->mapcor[0][map->colsizebuff - 1].x;
// 	dxmap = (inmax_x - map->mapcor[map->linesizebuff - 1][0].x);
// 	inmax_y = map->mapcor[map->linesizebuff - 1][map->colsizebuff - 1].y;
// 	dymap = (inmax_y - lowest_y);
// 	printf("size of rotmap; %d * %d", dxmap, dymap);
// 	if (inmax_x > map->colsizebuff || inmax_x < 0)
// 		return (dxmap / IMG_W);
// 	if (inmax_y > map->linesizebuff || inmax_y < 0)
// 		return (dymap / IMG_H);
// 	return (0);
// }

// static	void	shift(t_map *map, int lowest_y)
// {
// 	int	r;
// 	int	c;
// 	int	inmax_y;
// 	int	inmax_x;

// 	r = -1;
// 	inmax_x = map->mapcor[0][map->colsizebuff - 1].x;
// 	inmax_y = map->mapcor[map->linesizebuff - 1][map->colsizebuff - 1].y;
// 	while (++r < map->linesizebuff)
// 	{
// 		c = -1;
// 		while (++c < map->colsizebuff)
// 		{
// 			map->mapcor[r][c].x += inmax_x - map->mapcor[map->linesizebuff - 1][0].x;
// 			map->mapcor[r][c].y += (inmax_y - lowest_y);
// 			printf("(%d, %d, %d) sur line %d, col %d\n , shift= X;%d Y;%d", map->mapcor[r][c].x, map->mapcor[r][c].y, map->mapcor[r][c].z, r, c, 
// 				map->center_x - (inmax_x - map->mapcor[map->linesizebuff - 1][0].x), map->center_y - (inmax_y - lowest_y));
// 		}
// 	}
// }

void	my_mlx_pixel_putcolor(t_img *img, t_point *p, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (p->y * (img->line_len) + p->x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	laferme(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
}

void	create_coords(t_map *map)
{
	int		r;
	int		c;
	int		i;
	int		lowest_y;

	i = -1;
	r = 0;
	c = 0;
	map->mapcor = (t_point **)malloc(sizeof(t_point *) * map->linesizebuff);
	if (map->mapcor == NULL)
		panic("Malloc Error");
	while (++i < map->linesizebuff)
	{
		map->mapcor[i] = (t_point *)malloc(sizeof(t_point) * map->colsizebuff);
		if (map->mapcor[i] == NULL)
			panic("Malloc Error");
	}
	lowest_y = INT_MAX;
	while (r < map->linesizebuff)
	{
		while (c < map->colsizebuff)
		{
			map->mapcor[r][c].x = (c);
			map->mapcor[r][c].y = (r);
			map->mapcor[r][c].z = map->map[r][c];
			map->mapcor[r][c].x *= 10;
			map->mapcor[r][c].y *= 10;
			map->mapcor[r][c].z *= 10;
			rotate(&map->mapcor[r][c]);

			map->mapcor[r][c].x += 150;
			map->mapcor[r][c].y += 150;
			map->mapcor[r][c].z += 150;
			printf("(%d, %d, %d) sur line %d, col %d\n", map->mapcor[r][c].x, map->mapcor[r][c].y, map->mapcor[r][c].z, r, c);
			// transzoom(&map->mapcor[r][c], map);
			if (map->mapcor[r][c].y < lowest_y)
           		lowest_y = map->mapcor[r][c].y;
			c++;
		}
		printf("\n");
		c = 0;
		r++;
	}
	//shift(map, lowest_y);
	//apply_rot(map);
	// int res = resize(map, lowest_y);
	// printf("scalef %d ;", res);
	// if (res > 0 && res <= 1)
	// {
	// 	printf("Scalef = %d", res);
	// 	apply_resize(map, resize(map, lowest_y));
	// }
	printf("\nCoords added succesfully and lowest y is %d.\n", lowest_y);
}

void bresenham(t_point p, t_point p1, t_img	*img)
{
	t_point	ptmp;
    int dx = abs(p1.x - p.x);
    int dy = abs(p1.y - p.y);

    // //handle horizontal and vertical lines separately
	// if (dx == 0)
	// {
	// 	ptmp.y = p.y;
	// 	ptmp.x = p.x;
	// 	while (ptmp.y <= p1.y && ptmp.y < IMG_H && ptmp.y >= 0)
	// 	{	
	// 		//printf("YPrinting..(%d, %d, %d)", p.x, p.y, p.z);
	// 		my_mlx_pixel_putcolor(img, &ptmp, 0xFF0000);
	// 		ptmp.y++;
	// 	}
	// 	return ;
	// }
	// else if (dy == 0)
	// {
	// 	ptmp.x = p.x;
	// 	while (ptmp.x <= p1.x && ptmp.x < IMG_W && ptmp.x >= 0)
	// 	{
	// 		//printf("XPrinting..(%d, %d, %d)", p.x, p.y, p.z);
	// 		my_mlx_pixel_putcolor(img, &ptmp, 0xFF0000);
	// 		ptmp.x++;
	// 	}
	// 	return ;
	// }

	int x_step = p1.x > p.x ? 1 : -1;
	int y_step = p1.y > p.y ? 1 : -1;
	dx *= 2;
	dy *= 2;
	ptmp.x = p.x;
	ptmp.y = p.y;
	ptmp.z = p.z;
	int error = dx - dy;

	while (ptmp.x != p1.x && ptmp.y != p1.y)
	{
		if (ptmp.x >= 0 && ptmp.x < IMG_W && ptmp.y < IMG_H && ptmp.y >= 0)
		{
			//printf("(%d, %d, %d)", p.x, p.y, p.z);
			if (ptmp.z > 5)
				my_mlx_pixel_putcolor(img, &ptmp, 0x0000FF);
			else
				my_mlx_pixel_putcolor(img, &ptmp, 0xFF0000);
		}
		if (error > 0)
		{
			ptmp.x += x_step;
			error -= dy;
		}
		else
		{
			ptmp.y += y_step;
			error += dx;
		}
	}
	//printf("\n");
}

void	rendermap(t_map *map, t_point **mapcor, t_img *img)
{
	int	r;
	int	c;

	r = -1;
	while (++r < map->linesizebuff)
	{
		c = -1;
		while (++c < map->colsizebuff)
		{
			if (c < map->colsizebuff - 1)
				bresenham(mapcor[r][c], mapcor[r][(c + 1)], img);
			if (r < map->linesizebuff - 1)
				bresenham(mapcor[r][c], mapcor[(r + 1)][c], img);
		}
	}
	// c = 0;
	// while (c < map->colsizebuff - 1) {
   	// {
	// 	bresenham(mapcor[r][c], mapcor[r + 1][c], img);
    // 	c++;
	// }
}