/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:48 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:48 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	if (!*s2)
		return ((char*)s1);
	while (*s1 && *s2)
	{
		if (ft_memcmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
