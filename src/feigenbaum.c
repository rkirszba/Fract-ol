/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feigenbaum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:56:43 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:39:42 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	feigen_iteration(t_fractol *fractol, t_complex *c)
{
	int			iter;
	t_complex	z;

	iter = -1;
	z.real = 0;
	z.imag = 0;
	while (++iter < fractol->nb_iter)
	{
		z = square_complex(&z);
		z.real = z.real + c->real - 1.401115;
		z.imag = z.imag + c->imag;
		if ((double)square_module(&z) > 4)
			break ;
	}
	return (iter);
}

void		*display_feigen(void *arg)
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
			c = cube_complex(&c);
			nb_iter = feigen_iteration(fractol, &c);
			light_up_pixel(fractol, &pixel, nb_iter);
		}
	}
	pthread_exit(NULL);
}
