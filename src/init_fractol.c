/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:25:35 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 18:05:18 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_mlx_img(t_fractol *fractol, t_img *img, int img_wdth,\
		int img_hght)
{
	if (!(img->img_ptr = mlx_new_image(fractol->mlx.ptrs.mlx_ptr,\
		img_wdth, img_hght)))
		return (print_mlx_error(3));
	img->buf = mlx_get_data_addr(img->img_ptr,\
		&img->bits_per_pixel, &img->size_line, &img->endian);
	img->size_buf = img_wdth * img_hght * 4;
	img->plan.x_min = 0;
	img->plan.y_min = 0;
	img->plan.x_max = img_wdth;
	img->plan.y_max = img_hght;
	fractol->mlx_state++;
	return (0);
}

static int	init_mlx(t_fractol *fractol)
{
	int	i;

	if (!(fractol->mlx.ptrs.mlx_ptr = mlx_init()))
		return (print_mlx_error(1));
	fractol->mlx_state++;
	if (!(fractol->mlx.ptrs.win_ptr = mlx_new_window(fractol->mlx.ptrs.mlx_ptr,\
		WIN_WDTH, WIN_HGHT, "fractol")))
		return (print_mlx_error(2));
	fractol->mlx_state++;
	i = -1;
	if (init_mlx_img(fractol, &fractol->mlx.img, IMG_WDTH, IMG_HGHT))
		return (1);
	if (init_mlx_img(fractol, &fractol->mlx.img_menu, STRIPE_WDTH, IMG_HGHT))
		return (1);
	fractol->endian = fractol->mlx.img.endian;
	return (0);
}

static void	init_colors(t_fractol *fractol)
{
	fractol->color_tab_hexa[0][0] = PSET_0_COL_0;
	fractol->color_tab_hexa[0][1] = PSET_0_COL_1;
	fractol->color_tab_hexa[0][2] = PSET_0_COL_2;
	fractol->color_tab_hexa[0][3] = PSET_0_COL_3;
	fractol->color_tab_hexa[0][4] = PSET_0_COL_4;
	fractol->color_tab_hexa[1][0] = rand();
	fractol->color_tab_hexa[1][1] = rand();
	fractol->color_tab_hexa[1][2] = rand();
	fractol->color_tab_hexa[1][3] = rand();
	fractol->color_tab_hexa[1][4] = rand();
	fractol->color_tab_duo[0][0] = DSET_0_COL_0;
	fractol->color_tab_duo[0][1] = DSET_0_COL_1;
	fractol->color_tab_duo[1][0] = rand();
	fractol->color_tab_duo[1][1] = rand();
	fractol->color_uni[0] = USET_0;
	fractol->color_uni[1] = rand();
}

void		init_limits(t_fractol *fractol)
{
	static t_limit_values tab[NB_FRACTALS] = {{X_MIN_MANDEL, X_MAX_MANDEL,\
		Y_MIN_MANDEL}, {X_MIN_JULIA, X_MAX_JULIA, Y_MIN_JULIA},\
		{X_MIN_STAR, X_MAX_STAR, Y_MIN_STAR}, {X_MIN_LEAF, X_MAX_LEAF,\
		Y_MIN_LEAF}, {X_MIN_SCORPIONS, X_MAX_SCORPIONS, Y_MIN_SCORPIONS},\
		{X_MIN_SCORPIONS2, X_MAX_SCORPIONS2, Y_MIN_SCORPIONS2},\
		{X_MIN_FEIGEN, X_MAX_FEIGEN, Y_MIN_FEIGEN}, {X_MIN_SHIP, X_MAX_SHIP,\
		Y_MIN_SHIP}, {X_MIN_BATMAN, X_MAX_BATMAN, Y_MIN_BATMAN},\
		{X_MIN_TRIANGLE, X_MAX_TRIANGLE, Y_MIN_TRIANGLE}, {X_MIN_CIRCLE,\
		X_MAX_CIRCLE, Y_MIN_CIRCLE}, {X_MIN_INCA, X_MAX_INCA, Y_MIN_INCA},\
		{X_MIN_PSYCHE, X_MAX_PSYCHE, Y_MIN_PSYCHE}, {X_MIN_CRISTAL,\
		X_MAX_CRISTAL, Y_MIN_CRISTAL}};

	fractol->x_min = tab[fractol->fractal].x_min;
	fractol->x_max = tab[fractol->fractal].x_max;
	fractol->base_scale = (double)IMG_WDTH / (fractol->x_max - fractol->x_min);
	fractol->y_min = tab[fractol->fractal].y_min;
	fractol->y_max = fractol->y_min + (double)IMG_HGHT / fractol->base_scale;
}

int			init_fractol_structure(t_fractol *fractol, t_fractal fractal)
{
	fractol->fractal = fractal;
	if ((init_mlx(fractol)))
		return (1);
	init_colors(fractol);
	fractol->color_fctl = FIRST_COLOR;
	fractol->mods.subcolors = l_mlx_color_to_sub(fractol->color_fctl);
	init_limits(fractol);
	fractol->mods.coef_scale = 1;
	fractol->scale = fractol->base_scale;
	fractol->nb_iter = NB_ITER;
	return (0);
}
