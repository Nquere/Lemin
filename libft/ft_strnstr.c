/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:48 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:48 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (!*s2)
		return ((char*)s1);
	while (*s1 && *s2 && n > 0)
	{
		if (n >= ft_strlen(s2) && ft_memcmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char*)s1);
		s1++;
		n--;
	}
	return (NULL);
}
