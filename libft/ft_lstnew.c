/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:43 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:43 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	if ((lstnew = (t_list*)malloc(content_size)))
	{
		if (content != NULL)
		{
			lstnew->content = (void*)content;
			lstnew->content_size = content_size;
		}
		else
		{
			lstnew->content = NULL;
			lstnew->content_size = 0;
		}
		lstnew->next = NULL;
		return (lstnew);
	}
	return (NULL);
}
