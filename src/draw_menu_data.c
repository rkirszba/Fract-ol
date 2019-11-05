/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:53:54 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:36:30 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_dyn_fractal_data_cat(t_fractol *fractol, t_pixel *pixel)
{
	if (!(fractol->fractal == julia || fractol->fractal == inca\
		|| fractol->fractal == psyche))
		return ;
	fractol_putstr(&fractol->mlx.ptrs, pixel, "C value rpart       :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "C value ipart       :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "C value locked      :",\
		TITLE_SPACE);
}

static void	draw_fractal_dyn_data_val(t_fractol *fractol, t_pixel *pixel)
{
	char	*str;

	if (!(fractol->fractal == julia || fractol->fractal == inca\
		|| fractol->fractal == psyche))
		return ;
	str = ft_dtoa_prec(fractol->mods.julia_c.real, 6);
	fractol_putstr_free(&fractol->mlx.ptrs, pixel, str, TITLE_SPACE);
	str = ft_dtoa_prec(fractol->mods.julia_c.imag, 6);
	fractol_putstr_free(&fractol->mlx.ptrs, pixel, str, TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, fractol->lock ? "yes" : "no"\
		, TITLE_SPACE);
}

static void	draw_fractal_color_val(t_fractol *fractol, t_pixel *pixel)
{
	if (fractol->mods.color_nb == uni)
		fractol_putstr(&fractol->mlx.ptrs, pixel, "unicolor", TITLE_SPACE);
	else if (fractol->mods.color_nb == duo)
		fractol_putstr(&fractol->mlx.ptrs, pixel, "bicolor", TITLE_SPACE);
	else
		fractol_putstr(&fractol->mlx.ptrs, pixel, "multicolor", TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel,\
		fractol->mods.color_set == defined ? "predefined" : "random",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, fractol->mods.color_effect ==\
		gradient ? "gradient" : "ungradient", TITLE_SPACE);
}

void		draw_fractal_data_cat(t_fractol *fractol, t_pixel *pixel)
{
	fractol_putstr(&fractol->mlx.ptrs, pixel, "Maximal iterations  :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "Scale               :",\
		TITLE_SPACE);
	draw_dyn_fractal_data_cat(fractol, pixel);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "Mouse pointer rpart :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "Mouse pointer ipart :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "rpart min           :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "rpart max           :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "ipart min           :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "ipart mac           :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "Color mode          :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "Color set           :",\
		TITLE_SPACE);
	fractol_putstr(&fractol->mlx.ptrs, pixel, "Color effect        :",\
		TITLE_SPACE);
}

void		draw_fractal_data_val(t_fractol *fractol, t_pixel *pixel)
{
	char	*str;
	double	real;
	double	imag;

	str = ft_itoa(fractol->nb_iter);
	fractol_putstr_free(&fractol->mlx.ptrs, pixel, str, TITLE_SPACE);
	str = ft_dtoa_prec(fractol->scale, 6);
	fractol_putstr_free(&fractol->mlx.ptrs, pixel, str, TITLE_SPACE);
	draw_fractal_dyn_data_val(fractol, pixel);
	real = fractol->x_pix / fractol->scale + fractol->x_min;
	imag = fractol->y_pix / fractol->scale + fractol->y_min;
	str = ft_dtoa_prec(real, 6);
	fractol_putstr_free(&fractol->mlx.ptrs, pixel, str, TITLE_SPACE);
	str = ft_dtoa_prec(imag, 6);
	fractol_putstr_free(&fractol->mlx.ptrs, pixel, str, TITLE_SPACE);
	str = ft_dtoa_prec(fractol->x_min, 6);
	fractol_putstr_free(&fractol->mlx.ptrs, pixel, str, TITLE_SPACE);
	str = ft_dtoa_prec(fractol->x_max, 6);
	fractol_putstr_free(&fractol->mlx.ptrs, pixel, str, TITLE_SPACE);
	str = ft_dtoa_prec(fractol->y_min, 6);
	fractol_putstr_free(&fractol->mlx.ptrs, pixel, str, TITLE_SPACE);
	str = ft_dtoa_prec(fractol->y_max, 6);
	fractol_putstr_free(&fractol->mlx.ptrs, pixel, str, TITLE_SPACE);
	draw_fractal_color_val(fractol, pixel);
}
