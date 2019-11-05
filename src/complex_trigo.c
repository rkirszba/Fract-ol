/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_trigo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:35:11 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:17:27 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	cos_complex(t_complex *nb)
{
	t_complex	cos_nb;

	cos_nb.real = cos(nb->real) * cosh(nb->imag);
	cos_nb.imag = -sin(nb->real) * sinh(nb->imag);
	return (cos_nb);
}

t_complex	sin_complex(t_complex *nb)
{
	t_complex	sin_nb;

	sin_nb.real = sin(nb->real) * cosh(nb->imag);
	sin_nb.imag = cos(nb->real) * sinh(nb->imag);
	return (sin_nb);
}

t_complex	sinh_complex(t_complex *nb)
{
	t_complex	sinh_nb;

	sinh_nb.real = sinh(nb->real) * cos(nb->imag);
	sinh_nb.imag = cosh(nb->real) * sin(nb->imag);
	return (sinh_nb);
}

t_complex	exp_complex(t_complex *nb)
{
	double		exp_real;
	t_complex	exp_nb;

	exp_real = exp(nb->real);
	exp_nb.real = exp_real * cos(nb->imag);
	exp_nb.imag = exp_real * sin(nb->imag);
	return (exp_nb);
}

t_complex	ln_complex(t_complex *nb)
{
	t_complex	ln_nb;

	ln_nb.real = 0.5 * log(nb->real * nb->real + nb->imag * nb->imag);
	ln_nb.imag = atan(nb->imag / nb->real);
	return (ln_nb);
}
