/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:44 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:44 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;

	a = (char*)b;
	while (len--)
	{
		*a = (unsigned char)c;
		a++;
	}
	return (b);
}
