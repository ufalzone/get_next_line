/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:01:24 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/21 11:23:20 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
int		check_buffer(char *s);
int		ft_lenbuffer(char *str);
char	*extract_line(char *stock);
char	*update_stock(char *stock);
char	*get_next_line(int fd);
int		init_stock(char **stock);
char	*read_and_join(int fd, char *stock, char *buffer, int *bytes_read);


#endif
