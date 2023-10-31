/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:55:08 by rmatsuba          #+#    #+#             */
/*   Updated: 2023/10/31 14:06:25 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*keep_string[256];
	char		*result_string;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	keep_string[fd] = ft_read(fd, keep_string[fd]);
	if (!keep_string[fd])
		return (NULL);
	result_string = ft_get_line(keep_string[fd]);
	keep_string[fd] = ft_keep_str(keep_string[fd]);
	return (result_string);
}

char	*ft_read(int fd, char *keep_string)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(keep_string, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		keep_string = ft_strjoin(keep_string, buffer);
	}
	free(buffer);
	return (keep_string);
}

char	*ft_get_line(char *keep_string)
{
	int		i;
	char	*line_string;

	i = 0;
	if (!keep_string[i])
		return (NULL);
	while (keep_string[i] && keep_string[i] != '\n')
		i++;
	line_string = (char *)malloc(sizeof(char) * (i + 2));
	if (!line_string)
		return (NULL);
	i = 0;
	while (keep_string[i] && keep_string[i] != '\n')
	{
		line_string[i] = keep_string[i];
		i++;
	}
	if (keep_string[i] == '\n')
	{
		line_string[i] = keep_string[i];
		i++;
	}
	line_string[i] = '\0';
	return (line_string);
}

char	*ft_keep_str(char *keep_string)
{
	int		i;
	int		j;
	char	*after_n;

	i = 0;
	j = 0;
	while (keep_string[i] && keep_string[i] != '\n')
		i++;
	if (!keep_string[i])
	{
		free(keep_string);
		return (NULL);
	}
	after_n = malloc(sizeof(char) * (ft_strlen(keep_string) - i + 1));
	if (!after_n)
		return (NULL);
	i++;
	while (keep_string[i])
		after_n[j++] = keep_string[i++];
	after_n[j] = '\0';
	free(keep_string);
	return (after_n);
}
