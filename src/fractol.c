/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:19:26 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/29 16:14:51 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractals(t_fractal fractal)
{
	t_fractol			fractol;

	ft_bzero(&fractol, sizeof(t_fractol));
	if (init_fractol_structure(&fractol, fractal))
		exit_failure(&fractol, errno);
	display_fractal_routine(&fractol);
	events_handler(&fractol);
}

int			main(int ac, char **av)
{
	static char	*tab[NB_FRACTALS] = {"mandelbrot", "julia", "star", "leaf",\
		"scorpions", "scorpions2", "feigenbaum", "ship", "batman", "triangle",\
		"circle", "inca", "psyche", "cristal"};
	int			i;
	t_fractal	fractal;

	if (ac != 2)
		return (print_usage());
	i = -1;
	while (++i < NB_FRACTALS)
		if (!ft_strcmp(av[1], tab[i]))
		{
			fractal = (t_fractal)i;
			fractals(fractal);
		}
	if (i == NB_FRACTALS)
		return (print_usage());
	return (0);
}
