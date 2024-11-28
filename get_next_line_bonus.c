/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:46:12 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/28 15:50:26 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*stock[FD_MAX] = {NULL};
	char		*buffer;
	char		*line[FD_MAX] = {NULL};
	char		*temp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !init_stock(&stock[fd]))
		return (NULL);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && check_buffer(stock[fd]))
		stock[fd] = read_and_join(fd, stock[fd], buffer, &bytes_read);
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && stock[fd][0] == '\0'))
		return (free(stock[fd]), stock[fd] = NULL, NULL);
	if (!(line[fd] = extract_line(stock[fd])))
		return (free(stock[fd]), stock[fd] = NULL, NULL);
	temp = update_stock(stock[fd]);
	free(stock[fd]);
	stock[fd] = temp;
	return (line[fd]);
}

// #include <stdio.h>

// int	main(void)
// {
//     int     fd;
//     char    *str;

//     fd = open("test.txt", O_RDONLY);
//     str = get_next_line(fd);
//     while (str != NULL)
//     {
//         printf("%s", str);
//         free(str);
//         str = get_next_line(fd);
//     }
//     close(fd);
//     return (0);
// }