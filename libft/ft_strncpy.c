/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:47 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:47 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n && s2[index])
	{
		s1[index] = s2[index];
		index++;
	}
	while (index < n)
	{
		s1[index] = '\0';
		index++;
	}
	return (s1);
}
