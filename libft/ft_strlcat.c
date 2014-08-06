/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:47 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:47 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_cpy;
	char		*src_cpy;
	size_t		dst_len;
	int			n;

	dst_cpy = dst;
	src_cpy = (char*)src;
	n = size;
	while (n-- != 0 && *dst_cpy)
		dst_cpy++;
	dst_len = dst_cpy - dst;
	n = size - dst_len;
	if (n == 0)
		return (dst_len + ft_strlen(src));
	while (*src_cpy)
	{
		if (n-- > 1)
			*dst_cpy++ = *src_cpy;
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (dst_len + (src_cpy - src));
}
