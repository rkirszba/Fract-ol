/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:39:07 by rkirszba          #+#    #+#             */
/*   Updated: 2019/01/03 12:27:19 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(mapi = (char*)malloc(sizeof(*mapi) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		mapi[i] = f(i, (char)s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
