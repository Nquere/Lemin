/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:48 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:48 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int		ft_nb_str(char const *s, char c)
{
	int	nb_str;

	nb_str = 0;
	while (s != NULL && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			while (*s && *s != c)
				s++;
			nb_str++;
		}
	}
	return (nb_str);
}

static int		*ft_len_of_str(char const *s, char c, int nb_str)
{
	int				*ret;
	unsigned int	index;

	index = 0;
	if ((ret = (int*)ft_memalloc(sizeof(int) * nb_str)) && s != NULL)
	{
		while (*s)
		{
			while (*s && *s == c)
				s++;
			while (*s && *s != c)
			{
				ret[index]++;
				s++;
			}
			index++;
		}
		ret[nb_str] = 1;
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		nb_str;
	int		*len_of_str;

	ret = NULL;
	nb_str = ft_nb_str(s, c);
	len_of_str = ft_len_of_str(s, c, nb_str);
	if (s != NULL && (ret = (char**)malloc(sizeof(char*) * (nb_str + 1))))
	{
		while (*s)
		{
			while (*s && *s == c)
				s++;
			if (*s && *s != c)
			{
				*ret = ft_strsub(s, 0, *len_of_str);
				s = s + *len_of_str;
				ret++;
				len_of_str++;
			}
		}
		*ret = 0;
		free(len_of_str - nb_str);
	}
	return (ret - nb_str);
}
