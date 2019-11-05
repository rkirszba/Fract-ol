/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:31:32 by rkirszba          #+#    #+#             */
/*   Updated: 2019/05/30 14:12:37 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_case_null(void)
{
	char	**dup;

	if (!(dup = (char**)malloc(sizeof(char*))))
		return (NULL);
	ft_bzero(dup, sizeof(char*));
	return (dup);
}

char		**ft_splitdup(char **split)
{
	char	**dup;
	int		len;
	int		i;

	if (!split)
		return (ft_case_null());
	len = ft_splitlen(split);
	if (!(dup = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	ft_bzero(dup, sizeof(char*) * (len + 1));
	i = -1;
	while (++i < len)
		if (!(dup[i] = ft_strdup(split[i])))
		{
			ft_free_split(dup);
			return (NULL);
		}
	return (dup);
}
