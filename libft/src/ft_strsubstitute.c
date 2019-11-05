/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubstitute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:37:44 by rkirszba          #+#    #+#             */
/*   Updated: 2019/06/03 12:00:06 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsubstitute(char *s1, char *s2, size_t start, size_t end)
{
	char	*str;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2 || start > end)
		return (NULL);
	s1_len = ft_strlen(s1);
	if ((int)end >= s1_len)
		return (NULL);
	s2_len = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char)\
					* (s1_len + s2_len - (end - start + 1) + 1))))
		return (NULL);
	str[s1_len + s2_len - (end - start + 1)] = '\0';
	i = -1;
	while (++i < (int)start)
		str[i] = s1[i];
	j = -1;
	while (++j < s2_len)
		str[i++] = s2[j];
	while (s1[++end])
		str[i++] = s1[end];
	return (str);
}
