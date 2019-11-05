/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:31:54 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 11:47:38 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		print_usage(void)
{
	ft_putstr_fd("usage: ./fractol [mandelbrot | julia | star | leaf | ", 2);
	ft_putstr_fd("scorpions | scorpions2 | feigenbaum | ship | batman | ", 2);
	ft_putstr_fd("triangle | circle | inca | psyche | cristal]\n", 2);
	return (1);
}

int		print_sys_error(int errnum)
{
	ft_putstr_fd("fdf: error: ", 2);
	ft_putstr_fd(strerror(errnum), 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int		print_mlx_error(int errnum)
{
	ft_putstr_fd("fdf: error: ", 2);
	if (errnum == 1)
		ft_putstr_fd("Couldn't initialize MinilibX\n", 2);
	if (errnum == 2)
		ft_putstr_fd("Couldn't create a new window\n", 2);
	if (errnum == 1)
		ft_putstr_fd("Couldn't create a new image\n", 2);
	return (1);
}
