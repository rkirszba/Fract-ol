/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:12:29 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:14:38 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	square_complex(t_complex *nb)
{
	t_complex	square_nb;

	square_nb.real = nb->real * nb->real - nb->imag * nb->imag;
	square_nb.imag = 2 * nb->real * nb->imag;
	return (square_nb);
}

t_complex	cube_complex(t_complex *nb)
{
	t_complex	cube_nb;

	cube_nb.real = nb->real * (nb->real * nb->real - 3 * nb->imag * nb->imag);
	cube_nb.imag = 3 * nb->real * nb->real * nb->imag\
		- nb->imag * nb->imag * nb->imag;
	return (cube_nb);
}

t_complex	inverse_complex(t_complex *nb)
{
	t_complex	inverse_nb;

	inverse_nb.real = nb->real / (nb->real * nb->real + nb->imag * nb->imag);
	inverse_nb.imag = -nb->imag / (nb->real * nb->real + nb->imag * nb->imag);
	return (inverse_nb);
}

t_complex	product_complex(t_complex *n1, t_complex *n2)
{
	t_complex	product_nb;

	product_nb.real = n1->real * n2->real - n1->imag * n2->imag;
	product_nb.imag = n1->real * n2->imag + n2->real * n1->imag;
	return (product_nb);
}

double		square_module(t_complex *nb)
{
	return (nb->real * nb->real + nb->imag * nb->imag);
}
