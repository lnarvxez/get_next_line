/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:38:34 by lnarvaez          #+#    #+#             */
/*   Updated: 2022/05/24 15:38:37 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next(char *str)
{
	int		i;
	int		j;
	char	*linea;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	linea = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!linea)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		linea[j++] = str[i++];
	linea[j] = '\0';
	free (str);
	return (linea);
}

char	*ft_leer(char *str, int fd)
{
	int		leidos;
	char	*temporal;

	temporal = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temporal)
		return (NULL);
	leidos = 1;
	while (leidos > 0 && !ft_strchr(str, '\n'))
	{
		leidos = read(fd, temporal, BUFFER_SIZE);
		if (leidos == -1)
		{
			free (temporal);
			return (NULL);
		}
		temporal[leidos] = '\0';
		str = ft_strjoin(str, temporal);
	}
	free(temporal);
	return (str);
}

char	*ft_linea(char *str)
{
	char	*linea;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	linea = malloc(sizeof(char) * (i + 2));
	if (!linea)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		linea[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		linea[i] = str[i];
		i++;
	}
	linea[i] = '\0';
	return (linea);
}

char	*get_next_line(int fd)
{
	char		*linea;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (NULL);
	str[fd] = ft_leer(str[fd], fd);
	if (!str[fd])
		return (NULL);
	linea = ft_linea(str[fd]);
	str[fd] = ft_next(str[fd]);
	return (linea);
}
