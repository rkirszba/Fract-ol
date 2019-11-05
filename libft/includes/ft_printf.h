/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:51:16 by rkirszba          #+#    #+#             */
/*   Updated: 2019/05/21 13:45:09 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

# define DI		opt->conv == 'd' || opt->conv == 'i'
# define OUX	opt->conv == 'o' || opt->conv == 'u' || opt->conv == 'x'
# define XB		opt->conv == 'X' || opt->conv == 'b'
# define FLAGS (ft_strchr("#0-+ ", **format))
# define STAR (!(ft_strncmp("*", *format, 1)))
# define DIGIT (ft_isdigit(**format))
# define POINT (**format == '.')
# define THH (!(ft_strncmp("hh", *format, 2)))
# define TLL (!(ft_strncmp("ll", *format, 2)))
# define OTHERTYPES (**format == 'l' || **format == 'L' || **format == 'h')
# define CONV (ft_strchr("cspdiouxXfb%", (int)**format))

typedef struct		s_pfflags
{
	int				sharp;
	int				zero;
	int				minus;
	int				space;
	int				plus;
}					t_pfflags;

typedef enum		e_pfmodifier
{
	NONE,
	HH,
	H,
	L,
	LL,
	LLL,
}					t_pfmodifier;

typedef struct		s_pfoptions
{
	t_pfflags		flags;
	int				min_width;
	int				prec;
	t_pfmodifier	type;
	char			conv;
	int				arg_len;
	int				base;
	int				tot_len;
	int				flag_len;
}					t_pfoptions;

typedef struct		s_pflst
{
	char			*to_print;
	int				size;
	struct s_pflst	*next;
}					t_pflst;

int					ft_printf(const char *restrict format, ...);

/*
** analyse
*/

int					pf_parse_op(char **format, t_pfoptions *opt, va_list ap);
int					pf_parse_flags(char **format, t_pfoptions *opt);
int					pf_parse_width(char **format, t_pfoptions *opt, va_list ap);
int					pf_parse_prec(char **format, t_pfoptions *opt, va_list ap);
int					pf_parse_type(char **format, t_pfoptions *opt);
void				pf_parse_conv(char **format, t_pfoptions *opt);

/*
** recuperation arguments
*/

long long			pf_get_di(va_list ap, t_pfoptions *opt);
unsigned long long	pf_get_ouxxb(va_list ap, t_pfoptions *opt);

/*
** affichage erreurs
*/

int					pf_print_error(char **dup, t_pfoptions *opt);

/*
** affichage conversions habituelles
*/
int					pf_print_di(va_list ap, t_pfoptions *opt);
int					pf_print_ouxxpb(va_list ap, t_pfoptions *opt);
int					pf_print_s(va_list ap, t_pfoptions *opt);
int					pf_print_c(va_list ap, t_pfoptions *opt);

/*
** affichage pourcentage
*/

int					pf_print_pct(t_pfoptions *opt);

/*
** calcul largeur de champ
*/

void				pf_give_width_ouxxpb(t_pfoptions *opt,
					unsigned long long nb);
void				pf_give_width_di(t_pfoptions *opt, long long nb);

/*
** gestion padding
*/

void				pf_pad_plus(t_pfoptions *opt, long long nb,
					char **to_print);
void				pf_pad_space(t_pfoptions *opt, long long nb,
					char **to_print);
void				pf_pad_minus(t_pfoptions *opt, char **to_print);
void				pf_pad_zero(t_pfoptions *opt, char **to_print);
void				pf_pad_sharp(t_pfoptions *opt, unsigned long long nb,
					char **to_print);

/*
** conversion entiers en chaines
*/

void				pf_itoa_upbase(unsigned long long nb, t_pfoptions *opt,
					char **to_print);
void				pf_itoa_lowbase(unsigned long long nb, t_pfoptions *opt,
					char **to_print);
void				pf_itoa(long long nb, t_pfoptions *opt, char **to_print);

#endif
