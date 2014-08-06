/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:43 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:43 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_find_str_len(int n, int len)
{
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				len;
	int				is_neg;
	unsigned int	nb;

	is_neg = (n < 0) ? 1 : 0;
	nb = (n < 0) ? -n : n;
	len = ft_find_str_len(n, is_neg + 1);
	if ((ret = (char*)malloc(sizeof(char) * (len))))
	{
		if (nb == 0)
			*ret = '0';
		if (is_neg)
			*ret = '-';
		*(ret + len - 1) = '\0';
		while (nb != 0)
		{
			*(ret + (len--) - 2) = (char)(nb % 10 + '0');
			nb = nb / 10;
		}
	}
	return (ret);
}
