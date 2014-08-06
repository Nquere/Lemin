/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:46 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:46 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		index;

	index = -1;
	if ((s2 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
	{
		while (s1[++index])
			s2[index] = s1[index];
		s2[index] = '\0';
	}
	return (s2);
}
