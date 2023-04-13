/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:58:21 by smagniny          #+#    #+#             */
/*   Updated: 2023/04/06 15:51:27 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
