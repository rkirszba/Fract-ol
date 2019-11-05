/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:09:20 by rkirszba          #+#    #+#             */
/*   Updated: 2019/07/24 20:11:49 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(sub = (char*)malloc(sizeof(*sub) * len + 1)))
		return (0);
	while (i < len && s[i])
	{
		sub[i] = (char)s[(size_t)start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
