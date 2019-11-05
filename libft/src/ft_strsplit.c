/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:06:19 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/03 12:29:52 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_tbsize(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	if (s[i] == '\0' && s[i - 1] == c)
		j--;
	return (j);
}

static size_t	ft_strsize(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**split;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (!(split = (char**)malloc(sizeof(*split) * (ft_tbsize(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(split[j] = (char*)malloc(sizeof(**split) *
			(ft_strsize((s + i), c) + 1))))
				return (NULL);
			split[j] = ft_strccpy(split[j], (const char*)(s + i), c);
			i = i + ft_strsize((s + i), c) - 1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
