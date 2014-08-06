/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:48 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:41:31 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char			*ret;
	unsigned int	end;
	size_t			len;

	if (s != NULL)
	{
		while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
			s++;
		while (*s && (end = ft_strlen(s) - 1) != 0 &&
				(s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
			end--;
		len = end + 2;
		if ((ret = (char *)malloc(sizeof(char) * len)))
		{
			end = 0;
			while (end < len - 1)
			{
				ret[end] = s[end];
				end++;
			}
			ret[end] = '\0';
			return (ret);
		}
	}
	return (NULL);
}
