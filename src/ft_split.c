/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:25:58 by smagniny          #+#    #+#             */
/*   Updated: 2023/05/11 18:27:02 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

static int	ft_count_words(char const *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' || s[i] != '\n')
			nb++;
		while (s[i] && s[i] != c && s[i] != '\n')
			i++;
	}
	return (nb);
}

static char	*ft_place_word(char const *s, char c)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	while (s[len] && s[len] != c && s[len] != '\n')
			len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*ft_cpy_str(int i, char const *s, char c, char **res)
{
	res[i] = ft_place_word(s, c);
	if (!res[i])
	{
		while (i > 0)
		{
			i--;
			free(res[i]);
		}
		free(res);
		return (NULL);
	}
	return (res[i]);
}

char	**ssplit(char const *s, char c)
{
	int		nb_words;
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_count_words(s, c);
	printf("Words: %d", nb_words);
	res = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!res)
		return (NULL);
	while (i < nb_words)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			res[i] = ft_cpy_str(i, s, c, res);
		while (*s && *s != c)
			s++;
		i++;
	}
	res[i] = NULL;
	return (res);
}
