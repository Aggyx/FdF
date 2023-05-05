/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:48:01 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/05 14:31:59 by smagniny         ###   ########.fr       */
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
