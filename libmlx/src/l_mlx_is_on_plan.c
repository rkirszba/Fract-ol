/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mlx_is_on_plan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:16:52 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/01 12:47:46 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

int	l_mlx_is_x_on_plan(int x, t_plan *plan)
{
	if (x < plan->x_min || x > plan->x_max)
		return (0);
	return (1);
}

int	l_mlx_is_y_on_plan(int y, t_plan *plan)
{
	if (y < plan->y_min || y > plan->y_max)
		return (0);
	return (1);
}

int	l_mlx_is_on_plan(t_pixel *pixel, t_plan *plan)
{
	if (!l_mlx_is_x_on_plan(pixel->x, plan)
		|| !l_mlx_is_y_on_plan(pixel->y, plan))
		return (0);
	return (1);
}
