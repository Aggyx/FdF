/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsgetcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:39:31 by vbrazhni          #+#    #+#             */
/*   Updated: 2023/05/15 15:42:01 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 "fdf.h" for t_bool type
 "libft.h" for ft_toupper(), size_t type ("libft.h" includes <string.h>)
  and ft_isspace()
*/

#include "../inc/utils.h"
/*
 Check is this char present in selected numeral system
*/

static int	ft_isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

static t_bool	ft_has_prefix(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (False);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (True);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (True);
		if (base == 8)
			return (True);
	}
	return (False);
}

static	t_bool	ft_isnumber(char *str, int base)
{
	size_t		i;
	size_t		digits;

	i = 0;
	digits = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_has_prefix(&str[i], base))
		return (False);
	if (base == 16)
		i += 2;
	while (ft_isdigit_base(str[i], base) >= 0)
	{
		i++;
		digits++;
	}
	if (!str[i] && digits)
		return (True);
	return (False);
}

static	int	ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_has_prefix(&str[i], base))
		return (False);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit_base(str[i], base) >= 0)
		result = result * base + ft_isdigit_base(str[i++], base);
	return ((int)(result * sign));
}

int	retrieve_color(char *tmp)
{
	char	**parts;
	int		res;

	parts = ssplit(tmp, ',');
	if (ft_len(parts) <= 1)
	{
		doublefree(parts);
		return (0xFFFFFFFF);
	}
	else if (parts[1] && !ft_isnumber(parts[1], 16))
	{
		doublefree(parts);
		return (0xFFFFFFFF);
	}
	res = ft_atoi_base(parts[1], 16);
	doublefree(parts);
	return (res);
}
