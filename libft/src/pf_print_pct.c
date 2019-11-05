/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:51:01 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/22 12:57:33 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_handle_minus(t_pfoptions *opt)
{
	char	*to_print;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (!(to_print = ft_strnew(opt->tot_len)))
		exit(1);
	tmp = to_print;
	j = opt->tot_len - opt->arg_len;
	*to_print = '%';
	to_print++;
	while (i < j)
	{
		*to_print = ' ';
		to_print++;
		i++;
	}
	write(1, tmp, opt->tot_len);
	free(tmp);
}

static void	pf_handle_zero(t_pfoptions *opt)
{
	char	*to_print;
	char	*tmp;
	int		i;

	i = 0;
	if (!(to_print = ft_strnew(opt->tot_len)))
		exit(1);
	tmp = to_print;
	while (i < opt->tot_len - opt->arg_len)
	{
		*to_print = '0';
		to_print++;
		i++;
	}
	*to_print = '%';
	write(1, tmp, opt->tot_len);
	free(tmp);
}

static void	pf_handle_width(t_pfoptions *opt)
{
	char	*to_print;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (!(to_print = ft_strnew(opt->tot_len)))
		exit(1);
	tmp = to_print;
	j = opt->tot_len - opt->arg_len;
	while (i < j)
	{
		*to_print = ' ';
		to_print++;
		i++;
	}
	*to_print = '%';
	write(1, tmp, opt->tot_len);
	free(tmp);
}

int			pf_print_pct(t_pfoptions *opt)
{
	opt->arg_len = 1;
	opt->tot_len = opt->arg_len;
	opt->tot_len = (opt->min_width > opt->tot_len ? opt->min_width :
	opt->tot_len);
	if (opt->flags.minus)
		pf_handle_minus(opt);
	else if (opt->flags.zero && !opt->flags.minus && opt->prec == -1)
		pf_handle_zero(opt);
	else
		pf_handle_width(opt);
	return (opt->tot_len);
}
