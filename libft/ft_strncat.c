/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:47 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:47 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n != 0)
	{
		index = ft_strlen(s1);
		while (*s2 && n-- > 0)
		{
			s1[index] = *s2;
			index++;
			s2++;
		}
		s1[index] = '\0';
	}
	return (s1);
}
