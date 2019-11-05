/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_write_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:30:24 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/01 12:47:45 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** only works for bpp = 32
** endianess already taken care of
*/

#include "libmlx.h"

void	l_mlx_write_pixel(t_img *img, t_pixel *pixel)
{
	int	buf_pos;

	buf_pos = pixel->y * img->size_line + pixel->x * 4;
	if (l_mlx_is_on_plan(pixel, &img->plan) && buf_pos < img->size_buf)
		ft_memcpy((void*)(img->buf + buf_pos), (void*)(&pixel->color),\
			sizeof(int));
}
