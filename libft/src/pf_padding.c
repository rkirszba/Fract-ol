/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:41:48 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/23 14:03:40 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_pad_sharp(t_pfoptions *opt, unsigned long long nb, char **to_print)
{
	if (!opt->flags.sharp)
		return ;
	if (nb || opt->conv == 'p')
	{
		if (opt->conv == 'o')
		{
			**to_print = '0';
			(*to_print)++;
		}
		if (opt->conv == 'x' || opt->conv == 'p')
		{
			ft_strncpy(*to_print, "0x", 2);
			*to_print = *to_print + 2;
		}
		if (opt->conv == 'X')
		{
			ft_strncpy(*to_print, "0X", 2);
			*to_print = *to_print + 2;
		}
	}
}

void	pf_pad_zero(t_pfoptions *opt, char **to_print)
{
	int		i;

	i = 0;
	if (opt->prec != -1 || opt->flags.minus)
		return ;
	while (i < opt->tot_len - (opt->arg_len + opt->flag_len))
	{
		(*to_print)[i] = '0';
		i++;
	}
	*to_print = *to_print + i;
}

void	pf_pad_minus(t_pfoptions *opt, char **to_print)
{
	int		i;

	i = 0;
	while (i < opt->tot_len - (opt->prec > opt->arg_len ?
	(opt->prec + opt->flag_len) : (opt->arg_len + opt->flag_len)))
	{
		(*to_print)[i] = ' ';
		i++;
	}
	*to_print = *to_print + i;
}

void	pf_pad_space(t_pfoptions *opt, long long nb, char **to_print)
{
	if (opt->flags.space && nb >= 0 && opt->flags.plus == 0)
	{
		**to_print = ' ';
		(*to_print)++;
	}
}

void	pf_pad_plus(t_pfoptions *opt, long long nb, char **to_print)
{
	if (opt->flags.plus && nb >= 0)
	{
		**to_print = '+';
		(*to_print)++;
	}
}
