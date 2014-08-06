/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:44 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:44 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				ret;

	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	ret = 0;
	while (ret == 0 && n-- > 0)
	{
		ret = *a - *b;
		a++;
		b++;
	}
	return (ret);
}
