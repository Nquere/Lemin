/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:22:25 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:44:03 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "lem_in.h"

t_room		*ft_find_room(t_data_room data_room, char *room)
{
	t_room	*tmp;

	tmp = data_room.begin;
	while (tmp)
	{
		if (ft_strncmp(tmp->room, room, ft_strlen(room)) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		ft_check_cmd(t_data_line *data_line)
{
	if (ft_strcmp(data_line->line, "##start") == 0)
		data_line->is_start_end = 1;
	else if (ft_strcmp(data_line->line, "##end") == 0)
		data_line->is_start_end = 2;
	else
	{
		ft_putendl("ERROR");
		exit (0);
	}
}

void		ft_check_room(t_data_line *data_line, t_data_room *data_room)
{
	if (data_line->type_info == 1)
	{
		if (data_line->is_start_end == 1)
			data_line->start = ft_add_node(data_room, data_line->line);
		else if (data_line->is_start_end == 2)
			data_line->end = ft_add_node(data_room, data_line->line);
		else
			ft_add_node(data_room, data_line->line);
		data_line->is_start_end = 0;
	}
	else
	{
		ft_putendl("ERROR");
		exit(0);
	}
}

void		ft_check_tube(t_data_room data_r,
							t_data_line *data_l,
							t_data_tube *data_t)
{
	char	*room1;
	char	*room2;
	int		i;

	i = 0;
	data_l->type_info = 2;
	if (data_r.nb_node == 0 || data_l->type_info != 2)
	{
		ft_putendl("ERROR");
		exit(0);
	}
	else
	{
		while ((data_l->line)[i] != '-')
			i++;
		room1 = ft_strsub(data_l->line, 0, i);
		room2 = ft_strsub(data_l->line, i + 1,
				(ft_strlen(data_l->line) - i - 1));
		ft_add_tube(data_t, ft_find_room(data_r, room1),
					ft_find_room(data_r, room2));
	}
}

void		ft_check(t_data_room *data_room, t_data_tube *data_tube
					, t_data_line *data_line, t_data_nmale *data_nmale)
{
	if (data_line->line[0] == '#')
	{
		if (data_line->line[1] == '#')
			ft_check_cmd(data_line);
	}
	else if (data_line->type_info == 0)
	{
		if ((data_nmale->nb_nmale = ft_atoi(data_line->line)) > 0)
			data_line->type_info = 1;
		else
		{
			ft_putendl("ERROR");
			exit(0);
		}
	}
	else if (ft_strchr(data_line->line, ' ') != NULL)
		ft_check_room(data_line, data_room);
	else if (ft_strchr(data_line->line, '-') != NULL)
		ft_check_tube(*data_room, data_line, data_tube);
	else
	{
		ft_putendl("ERROR");
		exit(0);
	}
}
