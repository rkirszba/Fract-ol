/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:15:51 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 17:23:53 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_structure(t_fractol *fractol)
{
	if (fractol->mlx_state == 4)
		mlx_destroy_image(fractol->mlx.ptrs.mlx_ptr,\
			fractol->mlx.img_menu.img_ptr);
	if (fractol->mlx_state >= 3)
		mlx_destroy_image(fractol->mlx.ptrs.mlx_ptr,\
			fractol->mlx.img.img_ptr);
	if (fractol->mlx_state >= 2)
		mlx_destroy_window(fractol->mlx.ptrs.mlx_ptr,\
			fractol->mlx.ptrs.win_ptr);
}

void	exit_failure(t_fractol *fractol, int errnum)
{
	free_structure(fractol);
	exit(print_sys_error(errnum));
}
