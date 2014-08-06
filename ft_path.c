/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:22:25 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:45:07 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "lem_in.h"

void		ft_next(t_tube *tmp_tube, t_room *tmp_room, int index)
{
	while (tmp_tube)
	{
		if (ft_strcmp(tmp_tube->room1->room, tmp_room->room) == 0
			&& (tmp_room->index < tmp_tube->room2->index
				|| tmp_tube->room2->index == -1))
			tmp_tube->room2->index = index;
		else if (ft_strcmp(tmp_tube->room2->room, tmp_room->room) == 0
				&& (tmp_room->index < tmp_tube->room1->index
					|| tmp_tube->room1->index == -1))
			tmp_tube->room1->index = index;
		tmp_tube = tmp_tube->next;
	}
}

void		ft_putindex(t_data_tube data_tube, t_room *start, t_room *end)
{
	t_room	*tmp_room;
	t_tube	*tmp_tube;
	int		index;

	index = 0;
	end->index = -1;
	tmp_room = start;
	tmp_room->index = index;
	while (end->index == -1)
	{
		tmp_tube = data_tube.begin;
		if (tmp_room->is_busy == 0 && tmp_room->index == index)
		{
			index++;
			ft_next(tmp_tube, tmp_room, index);
		}
		tmp_room = tmp_room->next;
	}
}

void		ft_next_2(t_tube *tmp_tube, t_room *tmp_room, char **path, int i)
{
	while (tmp_tube)
	{
		if (ft_strcmp(tmp_tube->room1->room, tmp_room->room) == 0
			&& tmp_room->index - 1 == tmp_tube->room2->index)
			path[i] = ft_strdup(tmp_tube->room2->room);
		else if (ft_strcmp(tmp_tube->room2->room, tmp_room->room) == 0
				&& tmp_room->index - 1 == tmp_tube->room1->index)
			path[i] = ft_strdup(tmp_tube->room1->room);
		tmp_tube = tmp_tube->next;
	}
}

char		**ft_find_path(t_data_tube data_tube, t_room *start, t_room *end)
{
	t_room		*tmp_room;
	t_tube		*tmp_tube;
	char		**path;
	int			index;
	int			i;

	i = 0;
	tmp_room = end;
	ft_putindex(data_tube, start, end);
	index = end->index;
	if ((path = (char **)malloc(sizeof(char *) * (index + 2))) == NULL)
		return (NULL);
	path[i] = ft_strdup(tmp_room->room);
	while (index >= 0)
	{
		tmp_tube = data_tube.begin;
		if (tmp_room->is_busy == 0 && tmp_room->index == index)
		{
			i++;
			index--;
			ft_next_2(tmp_tube, tmp_room, path, i);
		}
		tmp_room = tmp_room->next;
	}
	return (path);
}
