/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:47 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:47 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ret;
	size_t		index;

	index = 0;
	ret = NULL;
	if (s != NULL && f != NULL && (ret = ft_strnew(ft_strlen(s) + 1)))
	{
		while (s[index])
		{
			ret[index] = (f)(index, s[index]);
			index++;
		}
		ret[index] = s[index];
	}
	return (ret);
}
