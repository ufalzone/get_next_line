/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:01:38 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/18 20:16:26 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_buffer(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_lenbuffer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

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

	i = 0;
	len_line = ft_lenbuffer(s1);
	line = malloc(sizeof(char) * (len_line + 1));
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
	char	*stock;
	int		update_size;
	int		i;

	i = 0;
	update_size = ft_strlen(s1) - ft_lenbuffer(s1);
    i = ft_lenbuffer(s1);
	stock = malloc(sizeof(char) * (update_size + 1));
	stock[ft_strlen(s1)] = '\0';
	while (s1[i])
	{
		stock[i] = s1[i];
		i++;
	}
    return (stock);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int size_total;
	char *resultat;
    int size1;
    int size2;
    int i;
	int j;

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