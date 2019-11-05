/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inca.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:11:52 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:44:24 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	inca_iteration(t_fractol *fractol, t_complex *z)
{
	int			iter;

	iter = -1;
	while (++iter < fractol->nb_iter)
	{
		*z = cube_complex(z);
		*z = exp_complex(z);
		z->real += fractol->mods.julia_c.real;
		z->imag += fractol->mods.julia_c.imag;
		if (square_module(z) > (double)10000000000)
			break ;
	}
	return (iter);
}

void		*display_inca(void *arg)
{
	t_fractol		*fractol;
	t_sub_img_lim	limits;
	t_pixel			pixel;
	t_complex		z;
	int				nb_iter;

	fractol = arg;
	limits = give_limits(fractol);
	pixel.y = limits.y0 - 1;
	while (++pixel.y < limits.y1)
	{
		pixel.x = limits.x0 - 1;
		while (++pixel.x < limits.x1)
		{
			z.real = (double)pixel.x / fractol->scale + fractol->x_min;
			z.imag = (double)pixel.y / fractol->scale + fractol->y_min;
			nb_iter = inca_iteration(fractol, &z);
			light_up_pixel(fractol, &pixel, nb_iter);
		}
	}
	pthread_exit(NULL);
}
