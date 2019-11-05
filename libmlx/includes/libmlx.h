/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:59:32 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/04 11:38:14 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

# include <math.h>
# include "mlx.h"
# include "libft.h"

# define X 0
# define Y 1
# define LITTLE 0
# define BIG 1
# define START 0
# define END 1

typedef struct	s_point
{
	double	x;
	double	y;
	int		color;
	int		endian;
}				t_point;

typedef struct	s_pixel
{
	int	x;
	int	y;
	int	color;
}				t_pixel;

typedef struct	s_plan
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}				t_plan;

typedef struct	s_ptrs
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ptrs;

typedef struct	s_img
{
	void	*img_ptr;
	char	*buf;
	int		bits_per_pixel;
	int		size_line;
	int		size_buf;
	t_plan	plan;
	int		endian;
}				t_img;

typedef struct	s_subcolors
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	alpha;
}				t_subcolors;

typedef struct	s_draw_line
{
	int		steep;
	double	y_intrsct;
	double	gradient;
	int		x_pxl_start;
	int		x_pxl_end;
}				t_draw_line;

void			l_mlx_write_pixel(t_img *img, t_pixel *pixel);
int				l_mlx_is_on_plan(t_pixel *pixel, t_plan *plan);
int				l_mlx_is_y_on_plan(int y, t_plan *plan);
int				l_mlx_is_x_on_plan(int x, t_plan *plan);
int				l_mlx_sub_to_color(t_subcolors sub, int endian);
unsigned char	l_mlx_compute_sub_color(unsigned char sub1, unsigned char sub2,\
	double percentage);
int				l_mlx_compute_color_big(int color1, int color2,\
	double percentage);
int				l_mlx_compute_color_little(int color1, int color2,\
	double percentage);
t_subcolors		l_mlx_color_to_sub(int color);

#endif
