/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:22:25 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:22:25 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "lem_in.h"

void		ft_init_s_data_nmale(t_data_nmale *data)
{
	data->begin = NULL;
	data->end = NULL;
	data->nb_nmale = 0;
}

t_nmale		*ft_create_nmale(void)
{
	t_nmale	*new;

	if ((new = (t_nmale*)malloc(sizeof(t_nmale))))
	{
		new->num = 0;
		new->pos = NULL;
		new->next = NULL;
	}
	return (new);
}

void		ft_create_nmale_list(t_data_nmale *data, t_room *start)
{
	t_nmale	*new;
	int		num;

	num = 1;
	while (num <= data->nb_nmale)
	{
		new = ft_create_nmale();
		new->num = num;
		new->pos = start->room;
		if (data->begin == NULL)
			data->begin = new;
		else
			data->end->next = new;
		data->end = new;
		new->next = data->begin;
		num++;
	}
}

void		ft_print_nmale(t_data_nmale data)
{
	t_nmale	*tmp;
	int		i;

	i = 0;
	tmp = data.begin;
	while (++i <= data.nb_nmale)
	{
		ft_putstr("Ant ");
		ft_putnbr(tmp->num);
		ft_putstr(" Pos: ");
		ft_put_til(tmp->pos, ' ');
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
