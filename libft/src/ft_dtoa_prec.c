/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_prec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:21:31 by rkirszba          #+#    #+#             */
/*   Updated: 2019/10/09 18:16:36 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	compute_nb_len(long long nb)
{
	size_t	i;

	nb = nb < 0 ? -nb : nb;
	i = 0;
	while (++i && nb >= 10)
		nb /= 10;
	return (i);
}

static void		fill_ipart(char *str, long long ipart, int ipart_len)
{
	ipart = ipart < 0 ? -ipart : ipart;
	while (--ipart_len >= 0)
	{
		str[ipart_len] = (ipart % 10) + '0';
		ipart /= 10;
	}
}

static void		fill_fpart(char *str, double nb, size_t prec)
{
	long long	ipart;

	if (!prec)
		return ;
	str[0] = '.';
	nb = nb < 0 ? -nb : nb;
	nb *= ft_power(10, (int)prec);
	ipart = nb;
	while ((int)prec > 0)
	{
		str[prec] = (ipart % 10) + '0';
		ipart /= 10;
		prec--;
	}
}

char			*ft_dtoa_prec(double nb, size_t prec)
{
	char		*str;
	long long	ipart;
	size_t		len;
	size_t		ipart_len;
	int			sign;

	len = 0;
	sign = 0;
	if (nb < 0)
	{
		len++;
		sign++;
	}
	len += prec + (prec ? 1 : 0);
	ipart = (long long)nb;
	ipart_len = compute_nb_len(ipart);
	len += ipart_len;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (sign)
		str[0] = '-';
	fill_ipart(str + (sign ? 1 : 0), ipart, ipart_len);
	fill_fpart(str + ipart_len + (sign ? 1 : 0), nb, prec);
	str[len] = '\0';
	return (str);
}
