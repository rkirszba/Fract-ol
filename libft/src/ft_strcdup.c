/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:36:37 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/21 21:24:51 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s1, int c)
{
	int		i;
	int		j;
	char	*dest;

	j = -1;
	if (!(ft_strchr(s1, c)))
	{
		if (!(dest = ft_strdup(s1)))
			return (NULL);
		return (dest);
	}
	else
	{
		i = ft_strchr(s1, c) - s1;
		if (!(dest = (char*)malloc(sizeof(*dest) * (i + 1))))
			return (NULL);
		while (++j < i)
			dest[j] = s1[j];
	}
	dest[j] = '\0';
	return (dest);
}
