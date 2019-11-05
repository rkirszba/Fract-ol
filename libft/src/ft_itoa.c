/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:33:44 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/03 12:16:10 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsize(int n)
{
	int		i;

	i = 1;
	if (n == -2147483648)
	{
		i = 11;
		return (i);
	}
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strsize(n);
	j = ft_strsize(n);
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	if (n == -2147483648)
		return (ft_strcpy(str, (const char*)"-2147483648"));
	if (n < 0)
		n = n * (-1);
	i--;
	while (i >= 0)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	if (j > 1 && str[0] == '0')
		str[0] = '-';
	return (str);
}
