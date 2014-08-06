/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:22:25 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:22:25 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include "lem_in.h"

t_room		*ft_add_node(t_data_room *data, char *room)
{
	t_room	*new;

	new = ft_create_node();
	if (data->begin == NULL)
	{
		data->begin = new;
		data->end = data->begin;
		data->begin->room = ft_strdup(room);
		data->end->next = data->begin;
	}
	else
	{
		data->end->next = new;
		data->end->next->next = data->begin;
		data->end->next->room = ft_strdup(room);
		data->end = data->end->next;
	}
	data->nb_node++;
	return (new);
}

void		ft_add_tube(t_data_tube *data, t_room *room1, t_room *room2)
{
	if (data->begin == NULL)
	{
		data->begin = ft_create_tube();
		data->end = data->begin;
		data->begin->room1 = room1;
		data->begin->room2 = room2;
		data->begin->next = NULL;
	}
	else
	{
		data->end->next = ft_create_tube();
		data->end->next->next = NULL;
		data->end->next->room1 = room1;
		data->end->next->room2 = room2;
		data->end = data->end->next;
	}
	data->nb_tube++;
}

void		ft_print_list(t_data_room data)
{
	t_room	*tmp;
	int		i;

	tmp = data.begin;
	i = 0;
	while (++i <= data.nb_node)
	{
		ft_putstr(tmp->room);
		ft_putstr(" index:");
		ft_putnbr(tmp->index);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void		ft_put_til(char *s, char c)
{
	while (*s != c)
	{
		write(1, s, 1);
		s++;
	}
}

void		ft_print_list_tube(t_data_tube data)
{
	t_tube	*tmp;

	tmp = data.begin;
	while (tmp)
	{
		ft_put_til(tmp->room1->room, ' ');
		ft_putchar('-');
		ft_put_til(tmp->room2->room, ' ');
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
