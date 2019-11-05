/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:12:58 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/21 23:40:33 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_handle_minus(t_pfoptions *opt, char *s)
{
	char	*to_print;
	char	*tmp;
	int		i;

	i = 0;
	if (!(to_print = ft_strnew(opt->tot_len)))
		exit(1);
	tmp = to_print;
	i = 0;
	ft_strncpy(to_print, s, opt->arg_len);
	to_print = to_print + opt->arg_len;
	while (i < opt->tot_len - opt->arg_len)
	{
		*to_print = ' ';
		to_print++;
		i++;
	}
	write(1, tmp, opt->tot_len);
	free(tmp);
}

static void	pf_handle_zero(t_pfoptions *opt, char *s)
{
	char	*to_print;
	char	*tmp;
	int		i;

	i = 0;
	if (!(to_print = ft_strnew(opt->tot_len)))
		exit(1);
	tmp = to_print;
	i = 0;
	while (i < opt->tot_len - opt->arg_len)
	{
		*to_print = '0';
		to_print++;
		i++;
	}
	ft_strncpy(to_print, s, opt->arg_len);
	write(1, tmp, opt->tot_len);
	free(tmp);
}

static void	pf_handle_width(t_pfoptions *opt, char *s)
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
		*to_print = ' ';
		to_print++;
		i++;
	}
	ft_strncpy(to_print, s, opt->arg_len);
	write(1, tmp, opt->tot_len);
	free(tmp);
}

int			pf_print_s(va_list ap, t_pfoptions *opt)
{
	char	*s;

	if (!(s = va_arg(ap, char*)))
	{
		write(1, "(null)", 6);
		return (6);
	}
	opt->arg_len = ft_strlen(s);
	if (opt->prec != -1 && opt->prec < opt->arg_len)
		opt->arg_len = opt->prec;
	opt->tot_len = opt->arg_len;
	opt->tot_len = (opt->min_width > opt->tot_len ? opt->min_width :
	opt->tot_len);
	if (opt->flags.minus)
		pf_handle_minus(opt, s);
	else if (opt->flags.zero && !opt->flags.minus)
		pf_handle_zero(opt, s);
	else
		pf_handle_width(opt, s);
	return (opt->tot_len);
}
