/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_sub_to_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:14:37 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/04 11:38:16 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

int		l_mlx_sub_to_color(t_subcolors sub, int endian)
{
	int		color;
	void	*ptr;

	color = 0;
	ptr = &color;
	if (endian == LITTLE)
	{
		ft_memcpy(ptr + 2, &(sub.red), sizeof(unsigned char));
		ft_memcpy(ptr + 1, &(sub.green), sizeof(unsigned char));
		ft_memcpy(ptr, &(sub.blue), sizeof(unsigned char));
		return (color);
	}
	ft_memcpy(ptr + 1, &(sub.red), sizeof(unsigned char));
	ft_memcpy(ptr + 2, &(sub.green), sizeof(unsigned char));
	ft_memcpy(ptr + 3, &(sub.blue), sizeof(unsigned char));
	return (color);
}
