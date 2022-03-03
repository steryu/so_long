/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:32:03 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/28 13:32:04 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (0);
}

char	*get_line(char **line, char **s)
{
	char	*temp;
	int		len;

	len = 0;
	temp = *s;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if (ft_strchr(*s, '\n'))
	{
		*line = ft_substr(*s, 0, len + 1);
		*s = ft_strdup(*s + len + 1);
	}
	else
	{
		*line = ft_strdup(temp);
		*s = NULL;
	}
	free(temp);
	return (*line);
}

int	read_file(int fd, char **line, char **buff, char **s)
{
	char	*temp;
	int		size;

	size = 1;
	while (size > 0)
	{
		size = read(fd, *buff, BUFFER_SIZE);
		(*buff)[size] = '\0';
		temp = ft_strjoin(*s, *buff);
		free(*s);
		*s = temp;
		if (ft_strchr(*buff, '\n'))
			break ;
	}
	free(*buff);
	get_line(line, s);
	return (size);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buff;
	char		*line;

	if (fd < 0)
		return (0);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	if (read(fd, buff, 0) < 0)
	{
		free(buff);
		return (0);
	}
	if (!s)
		s = ft_strdup("");
	if (read_file(fd, &line, &buff, &s) == 0 && *line == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}
