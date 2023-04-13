/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:48:01 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/06 15:58:13 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	size, size_t count)
{
	void	*ptr;

	if (size * count < count && size * count < size)
		return (0);
	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	else
		return (ft_memset(ptr, size, size * count));
}