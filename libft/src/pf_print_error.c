/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:39:20 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/23 14:04:10 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_minus(t_pfoptions *opt, char *cdup, char *to_print)
{
	int		i;

	i = 0;
	ft_strcpy(to_print, cdup);
	to_print = to_print + opt->arg_len;
	while (i < opt->tot_len - opt->arg_len - 1)
	{
		to_print[i] = ' ';
		i++;
	}
}

static void	pf_zero(t_pfoptions *opt, char *cdup, char *to_print)
{
	int		i;

	i = 0;
	while (i < opt->tot_len - opt->arg_len - 1)
	{
		to_print[i] = '0';
		i++;
	}
	ft_strcpy(to_print + i, cdup);
}

static void	pf_width(t_pfoptions *opt, char *cdup, char *to_print)
{
	int		i;

	i = 0;
	while (i < opt->tot_len - opt->arg_len - 1)
	{
		to_print[i] = ' ';
		i++;
	}
	ft_strcpy(to_print + i, cdup);
}

int			pf_print_error(char **dup, t_pfoptions *opt)
{
	char	*cdup;
	char	*to_print;
	char	*tmp;

	if (!(cdup = ft_strcdup((const char*)*dup, 37)))
		exit(1);
	opt->arg_len = ft_strlen(cdup);
	opt->tot_len = (opt->arg_len < opt->min_width) ? opt->min_width :
	opt->arg_len;
	if (!(to_print = ft_strnew(opt->tot_len)))
		exit(1);
	tmp = to_print;
	if (opt->flags.minus)
		pf_minus(opt, cdup, to_print);
	else if (opt->flags.zero && !opt->flags.minus)
		pf_zero(opt, cdup, to_print);
	else
		pf_width(opt, cdup, to_print);
	free(cdup);
	write(1, tmp, opt->tot_len);
	free(tmp);
	*dup = *dup + opt->arg_len;
	return (opt->tot_len);
}
