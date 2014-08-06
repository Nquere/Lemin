/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:22:25 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:22:25 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

void		ft_init_s_data_room(t_data_room *data)
{
	data->begin = NULL;
	data->end = NULL;
	data->nb_node = 0;
}

void		ft_init_s_data_line(t_data_line *data_line)
{
	data_line->line = NULL;
	data_line->type_info = 0;
	data_line->is_start_end = 0;
	data_line->start = NULL;
	data_line->end = NULL;
}

void		ft_init_s_data_tube(t_data_tube *data)
{
	data->begin = NULL;
	data->end = NULL;
	data->nb_tube = 0;
}

t_room		*ft_create_node(void)
{
	t_room	*new;

	if ((new = (t_room*)malloc(sizeof(t_room))))
	{
		new->room = NULL;
		new->index = -1;
		new->is_busy = 0;
		new->next = NULL;
	}
	return (new);
}

t_tube		*ft_create_tube(void)
{
	t_tube	*new;

	if ((new = (t_tube*)malloc(sizeof(t_tube))))
	{
		new->room1 = NULL;
		new->room2 = NULL;
		new->next = NULL;
	}
	return (new);
}
