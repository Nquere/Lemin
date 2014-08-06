/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:23:17 by nquere            #+#    #+#             */
/*   Updated: 2014/06/26 13:23:17 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libft.h>
# define BUFF_SIZE 1000

int		get_next_line(int const fd, char **line);
char	*ft_strchrsub(char *s, char c);
int		instanciate_line(char **buff, char **line);

#endif /* !GET_NEXT_LINE_H */
