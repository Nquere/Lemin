/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:22:25 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 15:30:19 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <get_next_line.h>
#include "lem_in.h"

int			ft_is_busy(t_data_nmale d_nmale, t_data_line d_line, char *room)
{
	int		counter;
	t_nmale	*tmp;

	counter = 0;
	tmp = d_nmale.begin;
	while (++counter <= d_nmale.nb_nmale)
	{
		if (ft_strcmp(tmp->pos, room) == 0
			&& ft_strcmp(tmp->pos, d_line.end->room) != 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		ft_init_data(t_data_line *data_line, t_data_room *data_room,
						t_data_tube *data_tube, t_data_print *data_print)
{
	ft_init_s_data_line(data_line);
	ft_init_s_data_room(data_room);
	ft_init_s_data_tube(data_tube);
	ft_init_s_data_print(data_print);
}

static void	print_path(t_data_print data_print, t_data_line data_line
						, t_data_tube data_tube, t_data_nmale *data_nmale)
{
	ft_create_nmale_list(data_nmale, data_line.start);
	ft_print_line(data_print);
	ft_putchar('\n');
	ft_move_nmale(data_nmale, data_line,
			ft_find_path(data_tube, data_line.start, data_line.end));
}

int			main(void)
{
	t_data_line		data_line;
	t_data_room		data_room;
	t_data_tube		data_tube;
	t_data_print	data_print;
	t_data_nmale	data_nmale;

	ft_init_data(&data_line, &data_room, &data_tube, &data_print);
	ft_init_s_data_nmale(&data_nmale);
	while (get_next_line(0, (&data_line.line)) > 0
			&& ft_strcmp(data_line.line, "\0") != 0)
	{
		ft_add_line(data_line.line, &data_print);
		ft_check(&data_room, &data_tube, &data_line, &data_nmale);
	}
	if (data_print.begin != NULL && data_room.begin != NULL
				&& data_tube.begin != NULL)
		print_path(data_print, data_line, data_tube, &data_nmale);
	else
		ft_putendl("ERROR");
	return (0);
}
