/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:36:17 by rkirszba          #+#    #+#             */
/*   Updated: 2019/08/07 17:46:37 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line2.h"

static int	fill_line(char **str, char **line)
{
	char	*n;
	char	*tmp;

	if ((n = ft_strchr((const char*)*str, '\n')))
	{
		*n = '\0';
		tmp = *str;
		if (!(*line = ft_strdup((const char*)*str)))
			return (0);
		if (!(*str = ft_strdup((const char*)(n + 1))))
			return (0);
		free(tmp);
	}
	else
	{
		if (**str)
		{
			tmp = *str;
			if (!(*line = ft_strdup((const char*)*str)))
				return (0);
			*str = ft_strnew(0);
			free(tmp);
		}
	}
	return (1);
}

static int	read_n(int fd, char **str)
{
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = *str;
		if (!(*str = ft_strjoin((char const*)*str, (char const*)buf)))
			return (0);
		free(tmp);
		if (ft_strchr((const char*)*str, '\n'))
			return (1);
	}
	return (1);
}

int			get_next_line2(int fd, char **line, char **str)
{
	char		buft[1];

	if (fd < 0 || !(line) || BUFF_SIZE <= 0 || read(fd, buft, 0) < 0 ||
			!str)
		return (-1);
	*line = NULL;
	if (*str == NULL)
		if (!(*str = ft_strnew(0)))
			return (-1);
	if ((ft_strchr((const char*)*str, '\n')))
	{
		if (!(fill_line(str, line)))
			return (-1);
	}
	else
	{
		if (!(read_n(fd, str)))
			return (-1);
		if (!(fill_line(str, line)))
			return (-1);
	}
	return ((*line) ? 1 : 0);
}
