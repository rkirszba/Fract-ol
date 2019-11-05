/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:25:19 by rkirszba          #+#    #+#             */
/*   Updated: 2018/11/12 21:56:50 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((const unsigned char*)src)[i] != (unsigned char)c)
	{
		((unsigned char*)dst)[i] = ((const unsigned char*)src)[i];
		i++;
	}
	if (i < n && ((const unsigned char*)src)[i] == (unsigned char)c)
	{
		((unsigned char*)dst)[i] = (unsigned char)c;
		return ((void*)(dst + i + 1));
	}
	else
		return (NULL);
}
