/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:47 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:47 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*ret;
	size_t		index;

	index = 0;
	ret = NULL;
	if (s != NULL && f != NULL && (ret = ft_strnew(ft_strlen(s) + 1)))
	{
		while (s[index])
		{
			ret[index] = (f)(s[index]);
			index++;
		}
		ret[index] = s[index];
	}
	return (ret);
}
