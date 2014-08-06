/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:22:45 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 15:31:25 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct		s_room
{
	char			*room;
	int				is_busy;
	int				index;
	struct s_room	*next;
}					t_room;

typedef struct		s_data_room
{
	struct s_room	*begin;
	struct s_room	*end;
	int				nb_node;
}					t_data_room;

typedef struct		s_data_tube
{
	struct s_tube	*begin;
	struct s_tube	*end;
	int				nb_tube;
}					t_data_tube;

typedef struct		s_tube
{
	t_room			*room1;
	t_room			*room2;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_data_line
{
	char			*line;
	int				type_info;
	int				is_start_end;
	t_room			*start;
	t_room			*end;
}					t_data_line;

typedef struct		s_print
{
	char			*line;
	struct s_print	*next;
}					t_print;

typedef struct		s_data_print
{
	struct s_print	*begin;
	struct s_print	*end;
}					t_data_print;

typedef struct		s_nmale
{
	int				num;
	char			*pos;
	struct s_nmale	*next;
}					t_nmale;

typedef struct		s_data_nmale
{
	struct s_nmale	*begin;
	struct s_nmale	*end;
	int				nb_nmale;
}					t_data_nmale;

void				ft_init_s_data_room(t_data_room *data);
void				ft_init_s_data_line(t_data_line *data_line);
void				ft_init_s_data_tube(t_data_tube *data);
t_room				*ft_create_node(void);
t_tube				*ft_create_tube(void);
t_room				*ft_add_node(t_data_room *data, char *room);
void				ft_add_tube(t_data_tube *data, t_room *room1
										, t_room *room2);
void				ft_put_til(char *s, char c);
void				ft_print_list(t_data_room data);
void				ft_print_list_tube(t_data_tube data);
void				ft_next(t_tube *tmp_tube, t_room *tmp_room, int index);
void				ft_putindex(t_data_tube data_tube
									, t_room *start, t_room *end);
void				ft_next_2(t_tube *tmp_tube, t_room *tmp_room
									, char **path, int i);
char				**ft_find_path(t_data_tube data_tube
							, t_room *start, t_room *end);
t_room				*ft_find_room(t_data_room data_room, char *room);
void				ft_check_cmd(t_data_line *data_line);
void				ft_check_room(t_data_line *data_line
							, t_data_room *data_room);
void				ft_check_tube(t_data_room data_r, t_data_line *data_l,
							t_data_tube *data_t);
void				ft_check(t_data_room *data_room, t_data_tube *data_tube
					, t_data_line *data_line, t_data_nmale *data_nmale);
void				ft_init_s_data_print(t_data_print *data);
void				ft_print_line(t_data_print data);
void				ft_add_line(char *line, t_data_print *dataprint);
void				ft_init_s_data_nmale(t_data_nmale *data);
t_nmale				*ft_create_nmale(void);
void				ft_create_nmale_list(t_data_nmale *data, t_room *start);
void				ft_print_nmale(t_data_nmale data);
void				ft_move_nmale(t_data_nmale *d_nmale, t_data_line d_line
										, char **path);
int					ft_is_busy(t_data_nmale d_nmale, t_data_line d_line
											, char *room);

#endif
