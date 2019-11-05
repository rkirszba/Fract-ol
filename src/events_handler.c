/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:11:16 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/29 15:33:46 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_events_handler(int keycode, t_fractol *fractol)
{
	static t_event	tab[KEY_EVENTS_NB] = {{MOVE_U, &handle_move_events},\
		{MOVE_D, &handle_move_events}, {MOVE_L, &handle_move_events}, {MOVE_R,\
		&handle_move_events}, {ZOOM_C_P, &handle_czoom_events}, {ZOOM_C_M,\
		&handle_czoom_events}, {ITER_P, &handle_iter_events},\
		{ITER_M, &handle_iter_events}, {RED_P, &handle_color_events}, {RED_M,\
		&handle_color_events}, {GREEN_P, &handle_color_events}, {GREEN_M,\
		&handle_color_events}, {BLUE_P, &handle_color_events}, {BLUE_M,\
		&handle_color_events}, {COLOR_NB, &handle_color_nb},\
		{COLOR_SET, &handle_color_set}, {COLOR_EFFECT, &handle_color_effect},\
		{RAND_COL, &handle_rand_col_event}, {RESET, &handle_reset_event},\
		{ESC, &handle_esc_event}};
	int				i;

	i = -1;
	while (++i < KEY_EVENTS_NB)
		if (tab[i].keycode == keycode)
			return (tab[i].function(keycode, fractol));
	return (0);
}

int		mouse_events_handler(int keycode, int x, int y, t_fractol *fractol)
{
	static t_event	tab[MOUSE_EVENTS_NB] = {{ZOOM_P_P, &handle_pzoom_events},\
		{ZOOM_P_M, &handle_pzoom_events}, {CENTER, &handle_center_event},\
		{LOCK, &handle_lock_event}};
	int				i;

	i = -1;
	while (++i < MOUSE_EVENTS_NB)
		if (tab[i].keycode == keycode)
		{
			fractol->x_pix = x;
			fractol->y_pix = y;
			return (tab[i].function(keycode, fractol));
		}
	return (0);
}

int		handle_quit_event_mouse(t_fractol *fractol)
{
	free_structure(fractol);
	exit(0);
}

int		mouse_motion_event_handler(int x, int y, t_fractol *fractol)
{
	fractol->x_pix = x;
	fractol->y_pix = y;
	if ((fractol->fractal == julia || fractol->fractal == inca\
		|| fractol->fractal == psyche) && !fractol->lock)
	{
		fractol->mods.julia_c.real = x / fractol->scale + fractol->x_min;
		fractol->mods.julia_c.imag = y / fractol->scale + fractol->y_min;
		display_fractal_routine(fractol);
	}
	draw_menu(fractol);
	return (0);
}

void	events_handler(t_fractol *fractol)
{
	mlx_hook(fractol->mlx.ptrs.win_ptr, RED_BUTTON, 0,
		&handle_quit_event_mouse, (void*)fractol);
	mlx_hook(fractol->mlx.ptrs.win_ptr, KEY_PRESS, 0, &key_events_handler,\
		(void*)fractol);
	mlx_hook(fractol->mlx.ptrs.win_ptr, MOUSE_PRESS, 0,\
		&mouse_events_handler, (void*)fractol);
	mlx_hook(fractol->mlx.ptrs.win_ptr, MOUSE_MOTION, 0,\
		&mouse_motion_event_handler, (void*)fractol);
	mlx_loop(fractol->mlx.ptrs.mlx_ptr);
}
