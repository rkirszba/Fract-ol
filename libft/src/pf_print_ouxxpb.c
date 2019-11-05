/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_ouxxpb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:21:42 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/22 14:27:33 by rkirszba         ###   ########.fr       */
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

static void	pf_handle_minus(t_pfoptions *opt, unsigned long long nb,
char *to_print)
{
	pf_pad_sharp(opt, nb, &to_print);
	pf_pad_prec(opt, &to_print);
	if (!((opt->conv == 'x' || opt->conv == 'X') && opt->prec == 0 && !nb)
	&& !(opt->conv == 'o' && !nb && opt->prec == 0 && !opt->flags.sharp)
	&& !(opt->conv == 'u' && !nb && opt->prec == 0)
	&& !(opt->conv == 'p' && !nb && opt->prec == 0))
		(opt->conv == 'x' || opt->conv == 'p') ? pf_itoa_lowbase(nb, opt,
		&to_print) : pf_itoa_upbase(nb, opt, &to_print);
	pf_pad_minus(opt, &to_print);
}

static void	pf_handle_zero(t_pfoptions *opt, unsigned long long nb,
char *to_print)
{
	pf_pad_sharp(opt, nb, &to_print);
	pf_pad_zero(opt, &to_print);
	if (!((opt->conv == 'x' || opt->conv == 'X') && opt->prec == 0 && !nb)
	&& !(opt->conv == 'o' && !nb && opt->prec == 0 && !opt->flags.sharp)
	&& !(opt->conv == 'u' && !nb && opt->prec == 0)
	&& !(opt->conv == 'p' && !nb && opt->prec == 0))
		(opt->conv == 'x' || opt->conv == 'p') ? pf_itoa_lowbase(nb, opt,
		&to_print) : pf_itoa_upbase(nb, opt, &to_print);
}

static void	pf_handle_width(t_pfoptions *opt, unsigned long long nb,
char *to_print)
{
	int		i;

	i = 0;
	while (i < opt->tot_len - (opt->flag_len + (opt->prec > opt->arg_len ?
	opt->prec : opt->arg_len)))
	{
		*to_print = ' ';
		to_print++;
		i++;
	}
	pf_pad_sharp(opt, nb, &to_print);
	pf_pad_prec(opt, &to_print);
	if (!((opt->conv == 'x' || opt->conv == 'X') && opt->prec == 0 && !nb)
	&& !(opt->conv == 'o' && !nb && opt->prec == 0 && !opt->flags.sharp)
	&& !(opt->conv == 'u' && !nb && opt->prec == 0)
	&& !(opt->conv == 'p' && !nb && opt->prec == 0))
		(opt->conv == 'x' || opt->conv == 'p') ? pf_itoa_lowbase(nb, opt,
		&to_print) : pf_itoa_upbase(nb, opt, &to_print);
}

int			pf_print_ouxxpb(va_list ap, t_pfoptions *opt)
{
	unsigned long long	nb;
	char				*to_print;

	if (opt->conv != 'p')
		nb = pf_get_ouxxb(ap, opt);
	else
	{
		nb = (unsigned long long)va_arg(ap, void*);
		opt->base = 16;
	}
	pf_give_width_ouxxpb(opt, nb);
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
