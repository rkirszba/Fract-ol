/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events_handlers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:52:46 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:47:59 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		handle_pzoom_events(int keycode, t_fractol *fractol)
{
	static int	tab[2] = {ZOOM_P_P, ZOOM_P_M};
	int			i;
	double		delta;

	i = -1;
	delta = 0;
	while (++i < 2)
		if (tab[i] == keycode)
		{
			delta = (1 + (!i ? DELTA_SCALE : -DELTA_SCALE));
			break ;
		}
	zoom_on_point(fractol, delta, fractol->x_pix, fractol->y_pix);
	fractol->mods.coef_scale = fractol->mods.coef_scale * delta;
	fractol->scale = fractol->mods.coef_scale * fractol->base_scale;
	display_fractal_routine(fractol);
	return (0);
}

int		handle_center_event(int keycode, t_fractol *fractol)
{
	(void)keycode;
	center_point(fractol);
	display_fractal_routine(fractol);
	return (0);
}

int		handle_lock_event(int keycode, t_fractol *fractol)
{
	(void)keycode;
	if (fractol->lock)
		fractol->lock = 0;
	else
		fractol->lock = 1;
	display_fractal_routine(fractol);
	return (0);
}
