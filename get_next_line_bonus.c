/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:46:12 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/28 18:18:43 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_total;
	char	*resultat;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size_total = (ft_strlen(s1) + ft_strlen(s2));
	resultat = malloc(sizeof(char) * (size_total + 1));
	if (!resultat)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		resultat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		resultat[i + j] = s2[j];
		j++;
	}
	resultat[i + j] = '\0';
	return (resultat);
}

char	*read_and_join(int fd, char *stock, char *buffer, int *bytes_read)
{
	char	*temp;

	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read > 0)
	{
		buffer[*bytes_read] = '\0';
		temp = ft_strjoin(stock, buffer);
		free(stock);
		return (temp);
	}
	return (stock);
}

char	*init_stock(char **stock)
{
	if (!*stock)
	{
		*stock = malloc(1);
		if (!*stock)
			return (NULL);
		(*stock)[0] = '\0';
	}
	return (*stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[FD_MAX] = {0};
	char		*buffer;
	char		*line;
	char		*temp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !init_stock(&stock[fd]))
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && check_buffer(stock[fd]))
		stock[fd] = read_and_join(fd, stock[fd], buffer, &bytes_read);
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && stock[fd][0] == '\0'))
		return (free(stock[fd]), stock[fd] = NULL, NULL);
	line = extract_line(stock[fd]);
	if (!line)
		return (free(stock[fd]), stock[fd] = NULL, NULL);
	temp = update_stock(stock[fd]);
	return (free(stock[fd]), stock[fd] = temp, line);
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