/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:42:41 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/22 13:22:35 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_handle_minus(t_pfoptions *opt, char c)
{
	char	*to_print;
	char	*tmp;
	int		i;

	i = 0;
	if (!(to_print = ft_strnew(opt->tot_len)))
		exit(1);
	tmp = to_print;
	*to_print = c;
	to_print++;
	while (i < opt->tot_len - 1)
	{
		*to_print = ' ';
		to_print++;
		i++;
	}
	write(1, tmp, opt->tot_len);
	free(tmp);
}

static void	pf_handle_zero(t_pfoptions *opt, char c)
{
	char	*to_print;
	char	*tmp;
	int		i;

	i = 0;
	if (!(to_print = ft_strnew(opt->tot_len)))
		exit(1);
	tmp = to_print;
	while (i < opt->tot_len - 1)
	{
		*to_print = '0';
		to_print++;
		i++;
	}
	*to_print = c;
	write(1, tmp, opt->tot_len);
	free(tmp);
}

static void	pf_handle_width(t_pfoptions *opt, char c)
{
	char	*to_print;
	char	*tmp;
	int		i;

	i = 0;
	if (!(to_print = ft_strnew(opt->tot_len)))
		exit(1);
	tmp = to_print;
	while (i < opt->tot_len - 1)
	{
		*to_print = ' ';
		to_print++;
		i++;
	}
	*to_print = c;
	write(1, tmp, opt->tot_len);
	free(tmp);
}

int			pf_print_c(va_list ap, t_pfoptions *opt)
{
	char	c;

	c = (char)va_arg(ap, int);
	opt->arg_len = 1;
	opt->min_width > opt->arg_len ? (opt->tot_len = opt->min_width) :
	(opt->tot_len = opt->arg_len);
	if (opt->flags.minus)
		pf_handle_minus(opt, c);
	else if (opt->flags.zero && !opt->flags.minus)
		pf_handle_zero(opt, c);
	else
		pf_handle_width(opt, c);
	return (opt->tot_len);
}
