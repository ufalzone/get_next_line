/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:46:12 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/18 20:18:37 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	char		*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	read(fd, buffer, BUFFER_SIZE);
	stock = ft_strjoin(stock, buffer);
	while (check_buffer(stock))
		// tant qu'il n'y a pas de \n la chaine se rajoute apres buffer
	{
		read(fd, buffer, BUFFER_SIZE);
		stock = ft_strjoin(stock, buffer);
	}
	line = extract_line(stock); 
		// créer une nouvelle chaîne contenant les caractères jusqu'au \n inclus
	stock = update_stock(stock);
		// créer une nouvelle chaîne avec les caractères restants après le \n
	return (line);
}

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;

	printf("salut");
	fd = open("test.txt", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}
