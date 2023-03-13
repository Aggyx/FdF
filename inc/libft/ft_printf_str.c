/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <smagniny@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:41:12 by smagniny          #+#    #+#             */
/*   Updated: 2022/12/12 18:26:20 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_putstr(char *s)
{	
	int	rtn;
	int	i;

	i = -1;
	rtn = 0;
	if (!s)
	{
		rtn += write(1, "(null)", 6);
		return (rtn);
	}
	while (s[++i])
	{
		rtn += ft_putchar(s[i]);
	}
	return (rtn);
}

int	ft_printf_str(char *str)
{	
	int	rtn;

	rtn = 0;
	if (str == NULL)
		rtn += ft_putstr("(null)");
	else
		rtn += ft_putstr(str);
	return (rtn);
}
