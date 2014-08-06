/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:17 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:17 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char		*buff = NULL;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (buff)
	{
		if (*line)
			ft_strclr(*line);
		if (instanciate_line(&buff, line))
			return (1);
		ft_strclr(buff);
	}
	else if ((*line = ft_strnew(0)))
		buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (instanciate_line(&buff, line))
			return (1);
	}
	ft_memdel((void **)&buff);
	return ((ret = **line ? 1 : 0));
}

char	*ft_strchrsub(char *s, char c)
{
	char			*tmp;
	int				index;

	index = 0;
	while (s[index] != c && s[index])
		index++;
	tmp = (char *)malloc(sizeof(char) * (index + 1));
	tmp[index] = '\0';
	while (index-- > 0)
		tmp[index] = s[index];
	return (tmp);
}

int		instanciate_line(char **buff, char **line)
{
	char			*tmp;
	int				index;

	index = 0;
	tmp = ft_strchrsub(*buff, '\n');
	if (*line)
		*line = ft_strjoin(*line, tmp);
	else
		*line = ft_strdup(tmp);
	ft_memdel((void **)&tmp);
	if (ft_memchr(*buff, '\n', ft_strlen(*buff)))
	{
		while ((*buff)[index] != '\n')
			index++;
		*buff = ft_strsub(*buff, (index + 1), ft_strlen(*buff) - index);
		return (1);
	}
	return (0);
}
