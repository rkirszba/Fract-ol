/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_color_events_handlers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:38:54 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:43:12 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_color_nb(int keycode, t_fractol *fractol)
{
	int	i;

	(void)keycode;
	i = fractol->mods.color_nb;
	i = (i + 1) % 3;
	fractol->mods.color_nb = i;
	display_fractal_routine(fractol);
	return (0);
}

int	handle_color_set(int keycode, t_fractol *fractol)
{
	int	i;

	(void)keycode;
	i = fractol->mods.color_set;
	i = (i + 1) % 2;
	fractol->mods.color_set = i;
	display_fractal_routine(fractol);
	return (0);
}

int	handle_color_effect(int keycode, t_fractol *fractol)
{
	int	i;

	(void)keycode;
	i = fractol->mods.color_effect;
	i = (i + 1) % 2;
	fractol->mods.color_effect = i;
	display_fractal_routine(fractol);
	return (0);
}

int	handle_rand_col_event(int keycode, t_fractol *fractol)
{
	int		i;

	(void)keycode;
	if (fractol->mods.color_set != randomed)
		return (0);
	i = -1;
	if (fractol->mods.color_nb == uni)
		fractol->color_uni[1] = rand();
	else if (fractol->mods.color_nb == duo)
		while (++i < 2)
			fractol->color_tab_duo[1][i] = rand();
	else
		while (++i < 6)
			fractol->color_tab_hexa[1][i] = rand();
	display_fractal_routine(fractol);
	return (0);
}

int	handle_color_events(int keycode, t_fractol *fractol)
{
	if (keycode == RED_M\
		&& fractol->mods.subcolors.red > 0 + DELTA_COL)
		fractol->mods.subcolors.red -= DELTA_COL;
	if (keycode == RED_P\
		&& fractol->mods.subcolors.red < 255 - DELTA_COL)
		fractol->mods.subcolors.red += DELTA_COL;
	if (keycode == GREEN_M\
		&& fractol->mods.subcolors.green > 0 + DELTA_COL)
		fractol->mods.subcolors.green -= DELTA_COL;
	if (keycode == GREEN_P\
		&& fractol->mods.subcolors.green < 255 - DELTA_COL)
		fractol->mods.subcolors.green += DELTA_COL;
	if (keycode == BLUE_M\
		&& fractol->mods.subcolors.blue > 0 + DELTA_COL)
		fractol->mods.subcolors.blue -= DELTA_COL;
	if (keycode == BLUE_P\
		&& fractol->mods.subcolors.blue < 255 - DELTA_COL)
		fractol->mods.subcolors.blue += DELTA_COL;
	fractol->color_fctl = l_mlx_sub_to_color(fractol->mods.subcolors,\
		fractol->endian);
	display_fractal_routine(fractol);
	return (0);
}
