/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:56:03 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/21 19:56:22 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_parse_conv(char **format, t_pfoptions *opt)
{
	opt->conv = **format;
	if (**format == 'i')
		opt->conv = 'd';
	if (opt->conv == 'p')
	{
		opt->type = L;
		opt->flags.sharp = 1;
	}
	if (opt->conv == 'o')
		opt->base = 8;
	if (opt->conv == 'x' || opt->conv == 'X' || opt->conv == 'p')
		opt->base = 16;
	if (opt->conv == 'b')
		opt->base = 2;
}
