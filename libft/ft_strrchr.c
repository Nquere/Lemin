/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:48 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:37:28 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char*)s;
	while (*s)
		s++;
	while (*s != (char)c && (size_t)(s - str) > 0)
		s--;
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
