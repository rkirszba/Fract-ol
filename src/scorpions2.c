/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scorpions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:33:10 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:58:37 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	scorpions2_iteration(t_fractol *fractol, t_complex *c)
{
	int			iter;
	t_complex	z;

	iter = -1;
	z.real = 1;
	z.imag = 0.1;
	while (++iter < fractol->nb_iter)
	{
		z = sinh_complex(&z);
		z.real += c->real;
		z.imag += c->imag;
		if (square_module(&z) > (double)1000000000)
			break ;
	}
	return (iter);
}

void		*display_scorpions2(void *arg)
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
			c = square_complex(&c);
			c = square_complex(&c);
			c = inverse_complex(&c);
			nb_iter = scorpions2_iteration(fractol, &c);
			light_up_pixel(fractol, &pixel, nb_iter);
		}
	}
	pthread_exit(NULL);
}
