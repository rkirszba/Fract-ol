/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_color_to_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 11:32:44 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 18:17:22 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

t_subcolors	l_mlx_color_to_sub(int color)
{
	t_subcolors	sub;

	sub.red = (unsigned char)(color >> 16 & 0xFF);
	sub.green = (unsigned char)(color >> 8 & 0xFF);
	sub.blue = (unsigned char)(color & 0xFF);
	return (sub);
}
