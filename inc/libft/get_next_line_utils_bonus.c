/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:58:21 by smagniny          #+#    #+#             */
/*   Updated: 2022/12/12 18:22:00 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoinfree(char *oldbuffer, char *tempbuffer)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = (char *)malloc(ft_strlen(oldbuffer) + ft_strlen(tempbuffer) + 1);
	if (!oldbuffer || !tempbuffer || !(new_str))
		return (0);
	i = 0;
	while (oldbuffer[i] != '\0')
	{
		new_str[i] = oldbuffer[i];
		i++;
	}
	j = 0;
	while (tempbuffer[j] != '\0')
		new_str[i++] = tempbuffer[j++];
	new_str[i] = '\0';
	free(oldbuffer);
	return (new_str);
}

int	find_occurrence(const char *s, int c)
{	
	while (*s && *s != c)
		s++;
	if (*s == 0)
		return (0);
	else
		return (1);
}

char	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size * count < count && size * count < size)
		return (0);
	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	else
		return (ft_memset(ptr, 0, size * count));
}
