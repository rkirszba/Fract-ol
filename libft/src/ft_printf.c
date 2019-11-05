/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:55:48 by rkirszba          #+#    #+#             */
/*   Updated: 2019/05/21 13:44:36 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_do_conv(va_list ap, char **dup)
{
	t_pfoptions	opt;

	(*dup)++;
	if (!(pf_parse_op(dup, &opt, ap)))
		return (pf_print_error(dup, &opt));
	else
	{
		if (!opt.conv)
			return (0);
		else if (ft_strchr("ouxXpb", opt.conv))
			return (pf_print_ouxxpb(ap, &opt));
		else if (opt.conv == 'd')
			return (pf_print_di(ap, &opt));
		else if (opt.conv == 's')
			return (pf_print_s(ap, &opt));
		else if (opt.conv == 'c')
			return (pf_print_c(ap, &opt));
		else if (opt.conv == '%')
			return (pf_print_pct(&opt));
	}
	return (0);
}

static int	pf_print_format(char **dup)
{
	int		len;
	char	*pct;

	if ((pct = ft_strchr((const char*)(*dup), 37)))
	{
		len = pct - *dup;
		write(1, *dup, len);
		*dup = pct;
	}
	else
	{
		len = ft_strlen(*dup);
		write(1, *dup, len);
		*dup = *dup + len;
	}
	return (len);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	char		*dup;
	char		*tmp;
	t_pflst		*alst;
	int			ret;

	ret = 0;
	if (!(dup = ft_strdup((const char*)format)))
		return (0);
	va_start(ap, format);
	tmp = dup;
	alst = NULL;
	while (*dup != '\0')
	{
		while (*dup == '%')
			ret = ret + pf_do_conv(ap, &dup);
		if (!(*dup))
			break ;
		ret = ret + pf_print_format(&dup);
	}
	free(tmp);
	return (ret);
}
