/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:11:31 by smagniny          #+#    #+#             */
/*   Updated: 2023/02/04 13:12:00 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	handle_input(int keypress, t_mlx mlx)
{
	printf("Keypress:%d\n", keypress);
	if (keypress == 53)
	{
		laferme(&mlx);
	}
	return (0);
}
