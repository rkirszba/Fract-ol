/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourmiz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:41:26 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:56:23 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	star_iteration(t_fractol *fractol, t_complex *c)
{
	int			iter;
	t_complex	z;

	iter = -1;
	z.real = 0;
	z.imag = 0;
	while (++iter < fractol->nb_iter)
	{
		z = square_complex(&z);
		z = cube_complex(&z);
		z.real += c->real;
		z.imag += c->imag;
		if ((double)square_module(&z) > 4)
			break ;
	}
	return (iter);
}

void		*display_star(void *arg)
{
	t_fractol		*fractol;
	t_sub_img_lim	limits;
	t_pixel			pixel;
	t_complex		c;
	int				nb_iter;

	fractol = arg;
	limits = give_limits(fractol);
	pixel.y = limits.y0 - 1;
	while (++pixel.y < limits.y1)
	{
		pixel.x = limits.x0 - 1;
		while (++pixel.x < limits.x1)
		{
			c.real = (double)pixel.x / fractol->scale + fractol->x_min;
			c.imag = (double)pixel.y / fractol->scale + fractol->y_min;
			c = inverse_complex(&c);
			nb_iter = star_iteration(fractol, &c);
			light_up_pixel(fractol, &pixel, nb_iter);
		}
	}
	pthread_exit(NULL);
}
