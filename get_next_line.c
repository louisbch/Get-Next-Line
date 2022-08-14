/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:21:31 by lbouchon          #+#    #+#             */
/*   Updated: 2022/08/14 15:15:01 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read(int fd, char *stash)
{
	char	*buf;
	int		read_byte;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_byte  = 1;
	while (!ft_strchr(buf, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
		 	free(buf);
		 	return (NULL);
		}
		stash = ft_strjoin(stash, buf);
		buf[read_byte] = '\0';
	}
	free(buf);
	return (stash);
}

char	*get_line(char *stash)
{
	char	*line;
	int		i;
	
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{ 
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
	{
		line[j] = stash[i];
		i++;
		j++;
	}
	line[i] = '\0';
	free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	// if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	// 	return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = ft_next(stash);
	return (line);
}

#include <fcntl.h>
int	main(void)
{
	char	*str;
	int		i;
	int		fd;

	i = 1;
	fd = open("test.txt", O_RDONLY);
	while (i != 0)
	{
		str = get_next_line(fd);
		if (!str)
			i = 0;
		else
			printf("%s", str);
	}
	printf("\n");
}
