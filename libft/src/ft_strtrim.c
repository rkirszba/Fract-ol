/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:54:08 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/03 12:31:24 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SPACE s[i] == ' ' || s[i] == '\n' || s[i] == '\t'

static int	ft_find_nsp(char const *s)
{
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	while (SPACE)
		i++;
	if (i == (int)j)
		i = 0;
	return (i);
}

static int	ft_findr_nsp(char const *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while ((int)i >= 0 && (SPACE))
		i--;
	if ((int)i == -1)
		i++;
	return ((int)i);
}

static char	*ft_trim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*trim;

	i = ft_find_nsp(s);
	j = ft_findr_nsp(s);
	k = 0;
	if (!(trim = (char*)malloc(sizeof(*trim) * ((j - i + 1) + 1))))
		return (NULL);
	if (i == 0 & j == 0)
	{
		trim[0] = '\0';
		return (trim);
	}
	while (i <= j)
	{
		trim[k] = (char)s[i];
		i++;
		k++;
	}
	trim[k] = '\0';
	return (trim);
}

char		*ft_strtrim(char const *s)
{
	if (!s)
		return (NULL);
	else
		return (ft_trim(s));
}
