/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:46:04 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 18:04:50 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		handle_move_events(int keycode, t_fractol *fractol)
{
	static int	tab[4] = {MOVE_U, MOVE_D, MOVE_L, MOVE_R};
	int			i;
	double		move;

	i = -1;
	while (++i < 4)
		if (tab[i] == keycode)
		{
			move = (DELTA_MOVE / fractol->scale) * (i % 2 ? 1 : -1);
			if (i < 2)
			{
				fractol->y_min += move;
				fractol->y_max += move;
			}
			else
			{
				fractol->x_min += move;
				fractol->x_max += move;
			}
			break ;
		}
	display_fractal_routine(fractol);
	return (0);
}

int		handle_czoom_events(int keycode, t_fractol *fractol)
{
	static int	tab[2] = {ZOOM_C_P, ZOOM_C_M};
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
	zoom_on_point(fractol, delta, IMG_WDTH / 2, IMG_HGHT / 2);
	fractol->mods.coef_scale = fractol->mods.coef_scale * delta;
	fractol->scale = fractol->mods.coef_scale * fractol->base_scale;
	display_fractal_routine(fractol);
	return (0);
}

int		handle_iter_events(int keycode, t_fractol *fractol)
{
	static int	tab[2] = {ITER_P, ITER_M};
	int			i;

	i = -1;
	while (++i < 2)
		if (tab[i] == keycode)
		{
			if (i == 0)
				fractol->nb_iter += DELTA_ITER;
			else if (fractol->nb_iter > DELTA_ITER)
				fractol->nb_iter -= DELTA_ITER;
			break ;
		}
	display_fractal_routine(fractol);
	return (0);
}

int		handle_reset_event(int keycode, t_fractol *fractol)
{
	(void)keycode;
	init_limits(fractol);
	fractol->color_fctl = FIRST_COLOR;
	fractol->mods.subcolors = l_mlx_color_to_sub(fractol->color_fctl);
	fractol->mods.coef_scale = 1;
	fractol->mods.color_effect = non_gradient;
	fractol->mods.color_nb = uni;
	fractol->mods.color_set = defined;
	fractol->lock = 0;
	fractol->scale = fractol->base_scale;
	fractol->nb_iter = NB_ITER;
	display_fractal_routine(fractol);
	return (0);
}

int		handle_esc_event(int keycode, t_fractol *fractol)
{
	(void)keycode;
	free_structure(fractol);
	exit(0);
}
