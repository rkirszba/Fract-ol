/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:20:27 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:20:51 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	center_point(t_fractol *fractol)
{
	fractol->x_min = fractol->x_min + (fractol->x_pix - (IMG_WDTH / 2))\
		/ fractol->scale;
	fractol->x_max = fractol->x_max + (fractol->x_pix - (IMG_WDTH / 2))\
		/ fractol->scale;
	fractol->y_min = fractol->y_min + (fractol->y_pix - (IMG_HGHT / 2))\
		/ fractol->scale;
	fractol->y_max = fractol->y_max + (fractol->y_pix - (IMG_HGHT / 2))\
		/ fractol->scale;
}

void	zoom_on_point(t_fractol *fractol, double delta, int x, int y)
{
	double	x_plan;
	double	y_plan;

	x_plan = x / fractol->scale + fractol->x_min;
	y_plan = y / fractol->scale + fractol->y_min;
	fractol->x_min = x_plan - ((x_plan - fractol->x_min) / delta);
	fractol->x_max = x_plan + ((fractol->x_max - x_plan) / delta);
	fractol->y_min = y_plan - ((y_plan - fractol->y_min) / delta);
	fractol->y_max = y_plan + ((fractol->y_max - y_plan) / delta);
}
