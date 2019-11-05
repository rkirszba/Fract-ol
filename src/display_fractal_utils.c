/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fractal_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:53:21 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 18:04:29 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		non_gradient_mode(t_fractol *fractol, t_pixel *pixel,\
		double pct)
{
	int	set;
	int	index;

	set = fractol->mods.color_set;
	if (fractol->mods.color_nb == uni)
		pixel->color = fractol->color_uni[set];
	else if (fractol->mods.color_nb == duo)
	{
		index = (int)(pct * 2);
		pixel->color = fractol->color_tab_duo[set][index];
	}
	else
	{
		index = (int)(pct * 5);
		pixel->color = fractol->color_tab_hexa[set][index];
	}
}

static void		gradient_mode(t_fractol *fractol, t_pixel *pixel,\
		double pct)
{
	int	set;
	int	index;

	set = fractol->mods.color_set;
	if (fractol->mods.color_nb == uni)
		pixel->color = (fractol->endian == little ?\
			l_mlx_compute_color_little(fractol->color_uni[set], 0xFFFFFF, pct)\
			: l_mlx_compute_color_big(fractol->color_uni[set], 0xFFFFFF, pct));
	else if (fractol->mods.color_nb == duo)
		pixel->color = (fractol->endian == little ?\
			l_mlx_compute_color_little(fractol->color_tab_duo[set][0],\
			fractol->color_tab_duo[set][1], pct) :\
			l_mlx_compute_color_big(fractol->color_tab_duo[set][0],\
			fractol->color_tab_duo[set][1], pct));
	else
	{
		index = (int)(pct * 5);
		pct = (pct - (double)index * 0.2) / 0.2;
		pixel->color = (fractol->endian == little ?\
			l_mlx_compute_color_little(fractol->color_tab_hexa[set][index],\
			fractol->color_tab_hexa[set][index + 1], pct) :\
			l_mlx_compute_color_big(fractol->color_tab_hexa[set][index],\
			fractol->color_tab_hexa[set][index + 1], pct));
	}
}

void			light_up_pixel(t_fractol *fractol, t_pixel *pixel, int nb_iter)
{
	double pct;

	if (nb_iter >= fractol->nb_iter)
		pixel->color = fractol->color_fctl;
	else
	{
		pct = (double)nb_iter / (double)fractol->nb_iter;
		if (fractol->mods.color_effect == non_gradient)
			non_gradient_mode(fractol, pixel, pct);
		else
			gradient_mode(fractol, pixel, pct);
	}
	l_mlx_write_pixel(&fractol->mlx.img, pixel);
}

t_sub_img_lim	give_limits(t_fractol *fractol)
{
	t_sub_img_lim	limits;
	int				current_thread;
	pthread_t		thread_id;

	current_thread = -1;
	thread_id = pthread_self();
	while (++current_thread < NB_THREADS)
		if (fractol->thread_tab[current_thread] == thread_id)
			break ;
	limits.x0 = current_thread * SUB_IMAGE_WDTH;
	limits.x1 = (current_thread == NB_THREADS - 1 ?\
		IMG_WDTH : limits.x0 + SUB_IMAGE_WDTH);
	limits.y0 = 0;
	limits.y1 = IMG_HGHT;
	return (limits);
}
