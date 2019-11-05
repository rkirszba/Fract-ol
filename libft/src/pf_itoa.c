/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:11:31 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/23 14:03:59 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_itoa_upbase(unsigned long long nb, t_pfoptions *opt, char **to_print)
{
	char	*tmp;
	char	*bases;
	int		i;

	i = 0;
	bases = "0123456789ABCDEF";
	if (!(tmp = ft_strnew(opt->arg_len)))
		exit(1);
	while (nb >= (unsigned long long)opt->base)
	{
		tmp[i] = bases[nb % opt->base];
		i++;
		nb = nb / opt->base;
	}
	tmp[i] = bases[nb % opt->base];
	ft_strrev(tmp);
	ft_strncpy(*to_print, tmp, opt->arg_len);
	*to_print = *to_print + opt->arg_len;
	free(tmp);
}

void	pf_itoa_lowbase(unsigned long long nb, t_pfoptions *opt,
char **to_print)
{
	char	*tmp;
	char	*bases;
	int		i;

	i = 0;
	bases = "0123456789abcdef";
	if (!(tmp = ft_strnew(opt->arg_len)))
		exit(1);
	while (nb >= (unsigned long long)opt->base)
	{
		tmp[i] = bases[nb % opt->base];
		i++;
		nb = nb / opt->base;
	}
	tmp[i] = bases[nb % opt->base];
	ft_strrev(tmp);
	ft_strncpy(*to_print, tmp, opt->arg_len);
	*to_print = *to_print + opt->arg_len;
	free(tmp);
}

void	pf_itoa(long long nb, t_pfoptions *opt, char **to_print)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_strnew(opt->arg_len)))
		exit(1);
	if (nb < 0)
		nb = nb * (-1);
	while (nb >= 10)
	{
		tmp[i] = nb % 10 + 48;
		i++;
		nb = nb / 10;
	}
	tmp[i] = nb % 10 + 48;
	ft_strrev(tmp);
	ft_strncpy(*to_print, tmp, opt->arg_len);
	*to_print = *to_print + opt->arg_len;
	free(tmp);
}
