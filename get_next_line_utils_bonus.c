/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:01:38 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/28 15:49:53 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_buffer(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_lenbuffer(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*extract_line(char *s1)
{
	char	*line;
	int		len_line;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	len_line = ft_lenbuffer(s1);
	if (len_line == -1)
		len_line = ft_strlen(s1);
	line = malloc(sizeof(char) * (len_line + 1));
	if (!line)
		return (NULL);
	line[len_line] = '\0';
	while (i < len_line)
	{
		line[i] = s1[i];
		i++;
	}
	return (line);
}

char	*update_stock(char *s1)
{
	char	*resultat;
	int		len_stock;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_lenbuffer(s1);
	if (j == -1)
		return (NULL);
	len_stock = ft_strlen(s1) - j;
	resultat = malloc(sizeof(char) * (len_stock + 1));
	if (!resultat)
		return (NULL);
	while (i < len_stock)
	{
		resultat[i] = s1[i + j];
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}

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

