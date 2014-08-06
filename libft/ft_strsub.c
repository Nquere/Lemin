/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:48 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:48 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		index;

	index = 0;
	if (s != NULL && (ret = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (len-- > 0)
			ret[index++] = (char)s[start++];
		ret[index] = '\0';
		return (ret);
	}
	return (NULL);
}
