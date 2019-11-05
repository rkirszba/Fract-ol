/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:05:28 by rkirszba          #+#    #+#             */
/*   Updated: 2019/07/24 15:41:24 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int			get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	char		buft[1];

	if (fd < 0 || !(line) || BUFF_SIZE <= 0 || read(fd, buft, 0) < 0)
		return (-1);
	*line = NULL;
	if (str == NULL)
		str = ft_strnew(0);
	if ((ft_strchr((const char*)str, '\n')))
	{
		if (!(fill_line(&str, line)))
			return (-1);
	}
	else
	{
		if (!(read_n(fd, &str)))
			return (-1);
		if (!(fill_line(&str, line)))
			return (-1);
	}
	return ((*line) ? 1 : 0);
}
