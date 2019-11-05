/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:01:11 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/29 16:09:33 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <errno.h>
# include <pthread.h>
# include "mlx.h"
# include "libmlx.h"
# include "libft.h"

/*
** core defines
*/

# define NB_FRACTALS 14
# define NB_THREADS 16
# define NB_ITER 30
# define FIRST_COLOR 0

/*
** dimensions defines
*/

# define WIN_WDTH 1370
# define WIN_HGHT 580

# define STRIPE_WDTH 500

# define IMG_WDTH (WIN_WDTH - STRIPE_WDTH)
# define IMG_HGHT WIN_HGHT

# define NB_SUB_IMAGES NB_THREADS
# define SUB_IMAGE_WDTH ((IMG_WDTH - STRIPE_WDTH) / NB_SUB_IMAGES)
# define SUB_IMAGE_HGHT IMG_HGHT

/*
** menu defines
*/

# define BG_COLOR 0xFF5261
# define X_MARGIN 30
# define Y_MARGIN 30
# define X_DATA_VAL_MARGIN 300
# define Y_DATA_MARGIN 100
# define BLOCK_SPACE 40
# define TITLE_SPACE 25

/*
** colors defines
*/

# define NB_SETS_H 2
# define NB_COLORS_H 6
# define PSET_0_COL_0 0x00A9FE
# define PSET_0_COL_1 0xC24CF6
# define PSET_0_COL_2 0xFF1493
# define PSET_0_COL_3 0xFC6E22
# define PSET_0_COL_4 0xFFFF66
# define PSET_0_COL_5 0xFFFF66

# define NB_SETS_D 2
# define NB_COLORS_D 2
# define DSET_0_COL_0 0xFF36D5
# define DSET_0_COL_1 0x9EFFF4

# define NB_SETS_U 2
# define USET_0 0x011BAD

/*
** events defines
*/

# define KEY_EVENTS_NB 20
# define KEY_PRESS 2

# define MOVE_U 126
# define MOVE_D 125
# define MOVE_L 123
# define MOVE_R 124
# define ZOOM_C_P 69
# define ZOOM_C_M 78
# define ITER_P 24
# define ITER_M 27
# define RED_P 15
# define RED_M 14
# define GREEN_P 5
# define GREEN_M 3
# define BLUE_P 11
# define BLUE_M 9
# define COLOR_NB 33
# define COLOR_SET 30
# define COLOR_EFFECT 42
# define RAND_COL 44
# define ESC 53
# define RESET 51

# define MOUSE_EVENTS_NB 4
# define MOUSE_PRESS 4

# define ZOOM_P_P 5
# define ZOOM_P_M 4
# define CENTER 1
# define LOCK 2

# define MOUSE_MOTION 6

# define RED_BUTTON 17

# define DELTA_MOVE 15
# define DELTA_SCALE 0.1
# define DELTA_ITER 1
# define DELTA_COL 7

/*
** fractals position defines
*/

# define X_MIN_MANDEL -2.5
# define X_MAX_MANDEL 1.7
# define Y_MIN_MANDEL -1.4

# define X_MIN_JULIA -2.0
# define X_MAX_JULIA 2.1
# define Y_MIN_JULIA -1.4

# define X_MIN_STAR -2.9
# define X_MAX_STAR 2.9
# define Y_MIN_STAR -1.9

# define X_MIN_LEAF -2.4
# define X_MAX_LEAF 2.3
# define Y_MIN_LEAF -1.54

# define X_MIN_SCORPIONS -55.9
# define X_MAX_SCORPIONS 55.2
# define Y_MIN_SCORPIONS -36.7

# define X_MIN_SCORPIONS2 -11.5
# define X_MAX_SCORPIONS2 11.4
# define Y_MIN_SCORPIONS2 -7.6

# define X_MIN_FEIGEN -2.0
# define X_MAX_FEIGEN 2.2
# define Y_MIN_FEIGEN -1.4

# define X_MIN_SHIP -2.5
# define X_MAX_SHIP 1.7
# define Y_MIN_SHIP -1.9

# define X_MIN_BATMAN -1.3
# define X_MAX_BATMAN 1.6
# define Y_MIN_BATMAN -0.95

# define X_MIN_TRIANGLE -2.7
# define X_MAX_TRIANGLE 3.1
# define Y_MIN_TRIANGLE -1.95

# define X_MIN_CIRCLE -1.53
# define X_MAX_CIRCLE 1.61
# define Y_MIN_CIRCLE -1.05

# define X_MIN_INCA -5.66
# define X_MAX_INCA 5.74
# define Y_MIN_INCA -3.64

# define X_MIN_PSYCHE -2.5
# define X_MAX_PSYCHE 1.7
# define Y_MIN_PSYCHE -1.0

# define X_MIN_CRISTAL -1.4
# define X_MAX_CRISTAL 1.5
# define Y_MIN_CRISTAL -0.9

typedef struct	s_mlx
{
	t_ptrs		ptrs;
	t_img		img;
	t_img		img_menu;
}				t_mlx;

typedef enum	e_endianess
{
	little,
	big
}				t_endianess;

typedef struct	s_complex
{
	double	real;
	double	imag;
}				t_complex;

typedef enum	e_color_effect
{
	non_gradient,
	gradient
}				t_color_effect;

typedef enum	e_color_nb
{
	uni,
	duo,
	hexa
}				t_color_nb;

typedef enum	e_color_set
{
	defined,
	randomed
}				t_color_set;

typedef struct	s_modifiers
{
	double				coef_scale;
	t_color_effect		color_effect;
	t_color_nb			color_nb;
	t_color_set			color_set;
	t_subcolors			subcolors;
	t_complex			julia_c;
}				t_modifiers;

typedef enum	e_fractal
{
	mandelbrot,
	julia,
	star,
	leaf,
	scorpions,
	scorpions2,
	feigen,
	ship,
	batman,
	triangle,
	circle,
	inca,
	psyche,
	cristal
}				t_fractal;

typedef struct	s_sub_img_lim
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}				t_sub_img_lim;

typedef struct	s_fractol
{
	t_fractal	fractal;
	t_mlx		mlx;
	t_endianess endian;
	pthread_t	thread_tab[NB_THREADS];
	int			nb_iter;
	double		base_scale;
	double		scale;
	int			color_tab_hexa[NB_SETS_H][NB_COLORS_H];
	int			color_tab_duo[NB_SETS_D][NB_COLORS_D];
	int			color_uni[NB_SETS_U];
	int			color_fctl;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			x_pix;
	int			y_pix;
	int			lock;
	t_modifiers	mods;
	int			mlx_state;
}				t_fractol;

typedef struct	s_limit_values
{
	double	x_min;
	double	x_max;
	double	y_min;
}				t_limit_values;

typedef struct	s_event
{
	int	keycode;
	int (*function)(int, t_fractol*);
}				t_event;

/*
** structure initialization
*/

int				init_fractol_structure(t_fractol *fractol, t_fractal fractal);
void			init_limits(t_fractol *fractol);

/*
** fractal routine displaying
*/

void			display_fractal_routine(t_fractol *fractol);

/*
** display fractals functions
*/

void			*display_mandelbrot(void *fractol);
void			*display_julia(void *arg);
void			*display_star(void *arg);
void			*display_leaf(void *arg);
void			*display_scorpions(void *arg);
void			*display_scorpions2(void *arg);
void			*display_feigen(void *arg);
void			*display_ship(void *arg);
void			*display_batman(void *arg);
void			*display_triangle(void *arg);
void			*display_circle(void *arg);
void			*display_inca(void *arg);
void			*display_psyche(void *arg);
void			*display_cristal(void *arg);

/*
** fractals utils functions
*/

double			square_module(t_complex *nb);
void			light_up_pixel(t_fractol *fractol, t_pixel *pixel, int nb_iter);
t_sub_img_lim	give_limits(t_fractol *fractol);

/*
** display utils
*/

void			center_point(t_fractol *fractol);
void			zoom_on_point(t_fractol *fractol, double delta, int x, int y);

/*
** operations on complexes
*/

t_complex		square_complex(t_complex *nb);
t_complex		cube_complex(t_complex *nb);
t_complex		inverse_complex(t_complex *nb);
t_complex		product_complex(t_complex *n1, t_complex *n2);
t_complex		cos_complex(t_complex *nb);
t_complex		sin_complex(t_complex *nb);
t_complex		sinh_complex(t_complex *nb);
t_complex		exp_complex(t_complex *nb);
t_complex		ln_complex(t_complex *nb);

/*
** events handlers
*/

void			events_handler(t_fractol *fractol);

int				key_events_handler(int keycode, t_fractol *fractol);
int				handle_move_events(int keycode, t_fractol *fractol);
int				handle_czoom_events(int keycode, t_fractol *fractol);
int				handle_iter_events(int keycode, t_fractol *fractol);
int				handle_color_events(int keycode, t_fractol *fractol);
int				handle_color_nb(int keycode, t_fractol *fractol);
int				handle_color_set(int keycode, t_fractol *fractol);
int				handle_color_effect(int keycode, t_fractol *fractol);
int				handle_rand_col_event(int keycode, t_fractol *fractol);
int				handle_reset_event(int keycode, t_fractol *fractol);
int				handle_esc_event(int keycode, t_fractol *fractol);

int				mouse_events_handler(int keycode, int x, int y,\
				t_fractol *fractol);
int				handle_pzoom_events(int keycode, t_fractol *fractol);
int				handle_center_event(int keycode, t_fractol *fractol);
int				handle_lock_event(int keycode, t_fractol *fractol);

int				handle_quit_event_mouse(t_fractol *fractol);

/*
** menu
*/

void			draw_menu(t_fractol *fractol);
void			draw_fractal_data_val(t_fractol *fractol, t_pixel *pixel);
void			draw_fractal_data_cat(t_fractol *fractol, t_pixel *pixel);
void			fractol_putstr_free(t_ptrs *ptrs, t_pixel *pixel, char *str,\
				int spacing);
void			fractol_putstr(t_ptrs *ptrs, t_pixel *pixel, char *str,\
				int spacing);

/*
** errors
*/

int				print_usage(void);
int				print_sys_error(int errnum);
int				print_mlx_error(int errnum);

/*
** exit functions
*/

void			exit_failure(t_fractol *fractol, int errnum);
void			free_structure(t_fractol *fractol);

#endif
