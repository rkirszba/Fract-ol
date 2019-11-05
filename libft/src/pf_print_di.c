/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:30:34 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/23 14:05:12 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_pad_prec(t_pfoptions *opt, char **to_print)
{
	int		i;

	i = 0;
	while (i < opt->prec - opt->arg_len)
	{
		**to_print = '0';
		i++;
		(*to_print)++;
	}
}

static void	pf_handle_minus(t_pfoptions *opt, long long nb, char *to_print)
{
	pf_pad_plus(opt, nb, &to_print);
	pf_pad_space(opt, nb, &to_print);
	if (nb < 0)
	{
		*to_print = '-';
		to_print++;
	}
	pf_pad_prec(opt, &to_print);
	if (nb == LONG_MIN || nb == LLONG_MIN)
	{
		ft_strcpy(to_print, "9223372036854775808");
		*to_print = *to_print + 19;
	}
	else if (!(opt->prec == 0 && !nb))
		pf_itoa(nb, opt, &to_print);
	pf_pad_minus(opt, &to_print);
}

static void	pf_handle_zero(t_pfoptions *opt, long long nb, char *to_print)
{
	if (nb < 0)
	{
		*to_print = '-';
		to_print++;
	}
	pf_pad_plus(opt, nb, &to_print);
	pf_pad_space(opt, nb, &to_print);
	pf_pad_zero(opt, &to_print);
	if (nb == LONG_MIN || nb == LLONG_MIN)
	{
		ft_strcpy(to_print, "9223372036854775808");
		*to_print = *to_print + 19;
	}
	else
		pf_itoa(nb, opt, &to_print);
}

static void	pf_handle_width(t_pfoptions *opt, long long nb, char *to_print)
{
	int		i;

	i = 0;
	while (i < opt->tot_len - (opt->flag_len + (opt->prec > opt->arg_len ?
	opt->prec : opt->arg_len)))
	{
		*to_print = ' ';
		i++;
		to_print++;
	}
	pf_pad_plus(opt, nb, &to_print);
	pf_pad_space(opt, nb, &to_print);
	if (nb < 0)
	{
		*to_print = '-';
		to_print++;
	}
	pf_pad_prec(opt, &to_print);
	if (nb == LONG_MIN || nb == LLONG_MIN)
	{
		ft_strcpy(to_print, "9223372036854775808");
		to_print = to_print + 19;
	}
	else if (!(opt->prec == 0 && !nb))
		pf_itoa(nb, opt, &to_print);
}

int			pf_print_di(va_list ap, t_pfoptions *opt)
{
	long long	nb;
	char		*to_print;

	nb = pf_get_di(ap, opt);
	pf_give_width_di(opt, nb);
	if (!(to_print = ft_strnew(opt->tot_len)))
		exit(1);
	if (opt->flags.minus)
		pf_handle_minus(opt, nb, to_print);
	else if (opt->flags.zero && !opt->flags.minus && opt->prec == -1)
		pf_handle_zero(opt, nb, to_print);
	else
		pf_handle_width(opt, nb, to_print);
	write(1, to_print, opt->tot_len);
	free(to_print);
	return (opt->tot_len);
}
