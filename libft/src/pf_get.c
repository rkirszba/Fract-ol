/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:24:34 by rkirszba          #+#    #+#             */
/*   Updated: 2019/05/21 13:44:44 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			pf_get_di(va_list ap, t_pfoptions *opt)
{
	if (opt->type == NONE)
		return (va_arg(ap, int));
	else if (opt->type == HH)
		return ((char)va_arg(ap, int));
	else if (opt->type == H)
		return ((short)va_arg(ap, int));
	else if (opt->type == L)
		return (va_arg(ap, long));
	else if (opt->type == LL)
		return (va_arg(ap, long long));
	else
		return (va_arg(ap, long long));
	return (0);
}

unsigned long long	pf_get_ouxxb(va_list ap, t_pfoptions *opt)
{
	if (opt->type == NONE)
		return (va_arg(ap, unsigned int));
	else if (opt->type == HH)
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (opt->type == H)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (opt->type == L)
		return (va_arg(ap, unsigned long));
	else if (opt->type == LL)
		return (va_arg(ap, unsigned long long));
	else
		return (va_arg(ap, unsigned long long));
	return (0);
}
