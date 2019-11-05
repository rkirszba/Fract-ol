/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:17:34 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 18:02:48 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractol_putstr(t_ptrs *ptrs, t_pixel *pixel, char *str, int spacing)
{
	if (!str)
		return ;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, pixel->x, pixel->y, 0xFFFFFF,\
		str);
	pixel->y += spacing;
}

void		fractol_putstr_free(t_ptrs *ptrs, t_pixel *pixel, char *str,\
		int spacing)
{
	if (!(str))
		return ;
	fractol_putstr(ptrs, pixel, str, spacing);
	free(str);
}

static void	draw_fractal_name(t_fractol *fractol, t_pixel *pixel)
{
	static char	*tab[NB_FRACTALS] = {"MANDELBROT", "JULIA", "STAR", "LEAF",\
		"SCORPIONS", "SCORPIONS2", "FEIGENBAUM", "SHIP", "BATMAN", "TRIANGLE",\
		"CIRCLE", "INCA", "PSYCHE", "CRISTAL"};

	fractol_putstr(&fractol->mlx.ptrs, pixel, tab[fractol->fractal],\
		TITLE_SPACE);
}

static void	paint_background(t_fractol *fractol)
{
	t_pixel	pixel;

	pixel.color = BG_COLOR;
	pixel.y = -1;
	while (++pixel.y < WIN_HGHT)
	{
		pixel.x = -1;
		while (++pixel.x < STRIPE_WDTH)
			l_mlx_write_pixel(&fractol->mlx.img_menu, &pixel);
	}
	mlx_put_image_to_window(fractol->mlx.ptrs.mlx_ptr,\
		fractol->mlx.ptrs.win_ptr, fractol->mlx.img_menu.img_ptr,\
		WIN_WDTH - STRIPE_WDTH, 0);
}

void		draw_menu(t_fractol *fractol)
{
	t_pixel	pixel;

	paint_background(fractol);
	pixel.x = WIN_WDTH - STRIPE_WDTH + X_MARGIN;
	pixel.y = Y_MARGIN;
	draw_fractal_name(fractol, &pixel);
	pixel.y = Y_DATA_MARGIN;
	draw_fractal_data_cat(fractol, &pixel);
	pixel.y = Y_DATA_MARGIN;
	pixel.x = WIN_WDTH - STRIPE_WDTH + X_DATA_VAL_MARGIN;
	draw_fractal_data_val(fractol, &pixel);
}
