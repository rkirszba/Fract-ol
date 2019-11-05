/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:11:06 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/23 14:06:46 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_parse_flags(char **format, t_pfoptions *opt)
{
	if (!(FLAGS || STAR || DIGIT || POINT || THH || TLL || OTHERTYPES || CONV))
		return (0);
	while (FLAGS)
	{
		if (**format == '#')
			opt->flags.sharp++;
		else if (**format == '0')
			opt->flags.zero++;
		else if (**format == '-')
			opt->flags.minus++;
		else if (**format == '+')
			opt->flags.plus++;
		else if (**format == ' ')
			opt->flags.space++;
		(*format)++;
	}
	return (1);
}

int			pf_parse_width(char **format, t_pfoptions *opt, va_list ap)
{
	if (!(FLAGS || STAR || DIGIT || POINT || THH || TLL || OTHERTYPES || CONV))
		return (0);
	if (DIGIT)
	{
		opt->min_width = ft_atoi(*format);
		while ((ft_isdigit(**format)))
			(*format)++;
	}
	else if (STAR)
	{
		opt->min_width = va_arg(ap, int);
		if (opt->min_width < 0)
		{
			opt->min_width = opt->min_width * -1;
			opt->flags.minus++;
		}
		(*format)++;
	}
	return (1);
}

int			pf_parse_prec(char **format, t_pfoptions *opt, va_list ap)
{
	if (!(FLAGS || STAR || DIGIT || POINT || THH || TLL || OTHERTYPES || CONV))
		return (0);
	if (POINT)
	{
		opt->prec = 0;
		(*format)++;
		if (ft_isdigit(**format))
		{
			opt->prec = ft_atoi(*format);
			while ((ft_isdigit(**format)))
				(*format)++;
		}
		else if (STAR)
		{
			opt->prec = va_arg(ap, int);
			if (opt->prec < 0)
				opt->prec = -1;
			(*format)++;
		}
	}
	return (1);
}

static void	pf_parse_type_else(char **format, t_pfoptions *opt)
{
	if (**format == 'l')
	{
		opt->type = L;
		(*format)++;
	}
	if (**format == 'L')
	{
		opt->type = LLL;
		(*format)++;
	}
	if (**format == 'h')
	{
		opt->type = H;
		(*format)++;
	}
}

int			pf_parse_type(char **format, t_pfoptions *opt)
{
	if (!(FLAGS || STAR || DIGIT || POINT || THH || TLL || OTHERTYPES || CONV))
		return (0);
	if (THH)
	{
		opt->type = HH;
		*format = *format + 2;
	}
	if (TLL)
	{
		opt->type = LL;
		*format = *format + 2;
	}
	pf_parse_type_else(format, opt);
	return (1);
}
