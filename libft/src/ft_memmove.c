/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:29:28 by rkirszba          #+#    #+#             */
/*   Updated: 2018/11/12 17:50:29 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len != 0)
	{
		if (dst < src)
			dst = ft_memcpy(dst, src, len);
		else
		{
			len--;
			while (len)
			{
				((unsigned char*)dst)[len] = ((const unsigned char*)src)[len];
				len--;
			}
			((unsigned char*)dst)[len] = ((const unsigned char*)src)[len];
		}
	}
	return (dst);
}
