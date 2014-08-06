/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:23:14 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 15:32:02 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <get_next_line.h>
#include "lem_in.h"

static void	ft_move(t_data_line d_line, t_nmale *tmp)
{
	if (ft_strcmp(tmp->pos, d_line.start->room) != 0)
	{
		ft_putchar('L');
		ft_putnbr(tmp->num);
		ft_putchar('-');
		ft_put_til(tmp->pos, ' ');
		ft_putchar(' ');
	}
}

void		ft_move_nmale(t_data_nmale *d_nmale, t_data_line d_line
		, char **path)
{
	t_nmale	*tmp;
	int		i;
	int		cpt;

	tmp = d_nmale->begin;
	cpt = d_nmale->nb_nmale;
	while (cpt > 0)
	{
		if (ft_strcmp(tmp->pos, d_line.end->room) != 0)
		{
			i = d_line.end->index;
			while (i >= 0 && ft_strcmp(tmp->pos, path[i]) != 0)
				i--;
			if (ft_strcmp(d_line.end->room, path[i]) != 0
					&& ft_is_busy(*d_nmale, d_line, path[i - 1]) == 0)
			{
				tmp->pos = path[i - 1];
				ft_move(d_line, tmp);
			}
			cpt = (ft_strcmp(tmp->pos, d_line.end->room) == 0) ? cpt - 1 : cpt;
			if (tmp == d_nmale->end)
				ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}
