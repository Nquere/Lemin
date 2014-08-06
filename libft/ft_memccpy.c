/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:44 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:44 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*a;
	char	*b;

	a = (char*)s1;
	b = (char*)s2;
	while (n--)
	{
		*a = *b;
		if (*b == c)
			return (a + 1);
		a++;
		b++;
	}
	return (NULL);
}
