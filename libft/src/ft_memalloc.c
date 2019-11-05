/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:36:31 by rkirszba          #+#    #+#             */
/*   Updated: 2018/11/10 14:19:41 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if (!(mem = (void*)malloc((sizeof(i) * size))))
		return (NULL);
	while (i < size)
	{
		((char*)mem)[i] = '\0';
		i++;
	}
	return (mem);
}
