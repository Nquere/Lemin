/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:45 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:45 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char*)s;
	while (((size_t)(s - str) <= ft_strlen(str) + 1) && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
