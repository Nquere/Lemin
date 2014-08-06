/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:22:24 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:22:24 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "lem_in.h"

void	ft_init_s_data_print(t_data_print *data)
{
	data->begin = NULL;
	data->end = NULL;
}

void	ft_print_line(t_data_print data)
{
	t_print		*tmp;

	tmp = data.begin;
	while (tmp)
	{
		ft_putendl(tmp->line);
		tmp = tmp->next;
	}
}

void	ft_add_line(char *line, t_data_print *dataprint)
{
	t_print		*new;

	new = (t_print *)malloc(sizeof(t_print));
	new->line = ft_strdup(line);
	new->next = NULL;
	if (dataprint->begin == NULL)
		dataprint->begin = new;
	else
		dataprint->end->next = new;
	dataprint->end = new;
}
