/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:46:12 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/20 14:35:16 by ufalzone         ###   ########.fr       */
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stock)
	{
		stock = malloc(1);
		if (!stock)
			return (NULL);
		stock[0] = '\0';
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && check_buffer(stock))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stock, buffer);
		free(stock);
		stock = temp;
	}
	free(buffer);
	if (bytes_read < 0)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	if (bytes_read == 0 && stock[0] == '\0')
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	line = extract_line(stock);
	temp = update_stock(stock);
	free(stock);
	stock = temp;
	if (!line)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
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