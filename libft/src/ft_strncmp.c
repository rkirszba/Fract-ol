/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:06:13 by rkirszba          #+#    #+#             */
/*   Updated: 2018/11/14 12:56:46 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] == s2[i] && (s1[i] && s2[i]) != '\0' && i < n)
		i++;
	if (i == n)
		i--;
	j = ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i];
	return (j);
}
