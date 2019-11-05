/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:33:36 by rkirszba          #+#    #+#             */
/*   Updated: 2019/05/20 19:45:57 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tlen;
	char	*join;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	tlen = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = (char*)malloc(sizeof(*join) * (tlen + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		join[i] = ((char*)s1)[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		join[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	join[tlen] = '\0';
	return (join);
}
