/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:46:12 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/21 11:23:11 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*buffer;
	char		*line;
	char		*temp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !init_stock(&stock))
		return (NULL);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && check_buffer(stock))
		stock = read_and_join(fd, stock, buffer, &bytes_read);
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && stock[0] == '\0'))
		return (free(stock), stock = NULL, NULL);
	if (!(line = extract_line(stock)))
		return (free(stock), stock = NULL, NULL);
	temp = update_stock(stock);
	free(stock);
	stock = temp;
	return (line);
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