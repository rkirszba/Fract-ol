/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cristal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:35:08 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:17:50 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	cristal_iteration(t_fractol *fractol, t_complex *c)
{
	int			iter;
	t_complex	z;
	t_complex	tmp_z1;
	t_complex	tmp_z2;

	iter = -1;
	z.real = 0;
	z.imag = 0;
	while (++iter < fractol->nb_iter)
	{
		tmp_z1 = square_complex(&z);
		tmp_z2.real = -1.00001 * z.real;
		tmp_z2.imag = -1.00001 * z.imag;
		tmp_z1.real += tmp_z2.real;
		tmp_z1.imag += tmp_z2.imag;
		tmp_z1 = product_complex(&tmp_z1, c);
		z = exp_complex(&tmp_z1);
		if (square_module(&z) > (double)1000000000)
			break ;
	}
	return (iter);
}

void		*display_cristal(void *arg)
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
			c.real = (double)((double)pixel.x / fractol->scale\
				+ fractol->x_min);
			c.imag = (double)((double)pixel.y / fractol->scale\
				+ fractol->y_min);
			c = cube_complex(&c);
			c = inverse_complex(&c);
			nb_iter = cristal_iteration(fractol, &c);
			light_up_pixel(fractol, &pixel, nb_iter);
		}
	}
	pthread_exit(NULL);
}
