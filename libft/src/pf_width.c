/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:26:14 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/21 19:59:18 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_give_nblen_di(long long nb, int base)
{
	int		len;

	len = 1;
	if (nb == LLONG_MIN)
		nb = LLONG_MIN + 1;
	if (nb < 0)
		nb = nb * (-1);
	while (nb >= base)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

static int	pf_give_nblen_ouxxpb(unsigned long long nb, int base)
{
	int		len;

	len = 1;
	while (nb >= (unsigned int)base)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

static void	pf_give_width_particular(t_pfoptions *opt, unsigned long long nb)
{
	if ((opt->conv == 'x' || opt->conv == 'X') && opt->prec == 0 && !nb)
	{
		opt->arg_len = 0;
		opt->tot_len = 0;
	}
	if (opt->conv == 'o' && !nb && opt->prec == 0 && !opt->flags.sharp)
	{
		opt->arg_len = 0;
		opt->tot_len = 0;
	}
	if (opt->conv == 'u' && !nb && opt->prec == 0)
	{
		opt->arg_len = 0;
		opt->tot_len = 0;
	}
	if (opt->conv == 'p' && !nb && opt->prec == 0)
	{
		opt->arg_len = 0;
		opt->tot_len = 2;
	}
}

void		pf_give_width_di(t_pfoptions *opt, long long nb)
{
	opt->arg_len = pf_give_nblen_di(nb, opt->base);
	if (opt->flags.plus && nb >= 0)
		opt->flag_len++;
	if (nb < 0)
		opt->flag_len++;
	if (opt->flags.space && !opt->flags.plus && nb >= 0)
		opt->flag_len++;
	opt->prec > opt->arg_len ? (opt->tot_len = opt->prec + opt->flag_len) :
	(opt->tot_len = opt->arg_len + opt->flag_len);
	if (opt->prec == 0 && !nb)
	{
		opt->arg_len = 0;
		opt->tot_len--;
	}
	opt->min_width > opt->tot_len ? opt->tot_len = opt->min_width :
	opt->tot_len;
}

void		pf_give_width_ouxxpb(t_pfoptions *opt, unsigned long long nb)
{
	opt->arg_len = pf_give_nblen_ouxxpb(nb, opt->base);
	if (opt->flags.sharp && opt->conv == 'o' && nb)
		opt->flag_len++;
	if (opt->flags.sharp && (opt->conv == 'x' || opt->conv == 'X') && nb)
		opt->flag_len = opt->flag_len + 2;
	if (opt->flags.sharp && opt->conv == 'p')
		opt->flag_len = opt->flag_len + 2;
	opt->prec > opt->arg_len ? (opt->tot_len = opt->prec + opt->flag_len) :
	(opt->tot_len = opt->arg_len + opt->flag_len);
	pf_give_width_particular(opt, nb);
	opt->min_width > opt->tot_len ? opt->tot_len = opt->min_width :
	opt->tot_len;
}
