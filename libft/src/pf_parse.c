/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:33:09 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/21 19:54:55 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_init_op(t_pfoptions *opt)
{
	opt->flags.sharp = 0;
	opt->flags.zero = 0;
	opt->flags.minus = 0;
	opt->flags.space = 0;
	opt->flags.plus = 0;
	opt->min_width = 0;
	opt->prec = -1;
	opt->type = NONE;
	opt->conv = 0;
	opt->arg_len = 0;
	opt->base = 10;
	opt->tot_len = 0;
	opt->flag_len = 0;
}

int			pf_parse_op(char **format, t_pfoptions *opt, va_list ap)
{
	pf_init_op(opt);
	while ((!(ft_strchr("cspdiouxXfb%", (int)**format))))
	{
		if (!(pf_parse_flags(format, opt)))
			return (0);
		if (!(pf_parse_width(format, opt, ap)))
			return (0);
		if (!(pf_parse_prec(format, opt, ap)))
			return (0);
		if (!(pf_parse_type(format, opt)))
			return (0);
	}
	pf_parse_conv(format, opt);
	(*format)++;
	return (1);
}
