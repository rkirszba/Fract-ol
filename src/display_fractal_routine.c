/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fractal_routine.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:12:42 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/29 15:33:33 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_fractal_routine(t_fractol *fractol)
{
	static void	*(*tab[NB_FRACTALS])(void*) = {display_mandelbrot,\
		display_julia, display_star, display_leaf, display_scorpions,\
		display_scorpions2, display_feigen, display_ship, display_batman,\
		display_triangle, display_circle, display_inca, display_psyche,\
		display_cristal};
	int			current_thread;

	current_thread = -1;
	ft_bzero(fractol->thread_tab, sizeof(pthread_t) * NB_THREADS);
	while (++current_thread < NB_THREADS)
	{
		if (pthread_create(&fractol->thread_tab[current_thread], NULL,\
			tab[fractol->fractal], (void*)(fractol)))
			exit_failure(fractol, errno);
	}
	current_thread = -1;
	while (++current_thread < NB_THREADS)
		if (pthread_join(fractol->thread_tab[current_thread], NULL))
			exit_failure(fractol, errno);
	mlx_put_image_to_window(fractol->mlx.ptrs.mlx_ptr,\
		fractol->mlx.ptrs.win_ptr, fractol->mlx.img.img_ptr, 0, 0);
	draw_menu(fractol);
	ft_bzero(fractol->mlx.img.buf, fractol->mlx.img.size_buf);
}
