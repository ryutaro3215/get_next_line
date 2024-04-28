/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:44:14 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/04/29 01:08:02 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *keep_string)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc(sizeof(char) * ((long)BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(keep_string));
	while (!ft_strchr(keep_string, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (ft_free(keep_string));
		}
		buffer[read_bytes] = '\0';
		keep_string = ft_strjoin(keep_string, buffer);
		if (!keep_string)
			return (ft_free(buffer));
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
	keep_string = check_end(keep_string, i);
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

char	*ft_keep_str(char *keep_string, char *result_string)
{
	int		i;
	int		j;
	char	*after_n;

	i = 0;
	j = 0;
	if (!result_string)
		return (ft_free(keep_string));
	while (keep_string[i] && keep_string[i] != '\n')
		i++;
	if (!keep_string[i])
		return (ft_free(keep_string));
	after_n = malloc(sizeof(char) * (ft_strlen(keep_string) - i + 1));
	if (!after_n)
	{
		free(result_string);
		return (ft_free(keep_string));
	}
	i++;
	while (keep_string[i])
		after_n[j++] = keep_string[i++];
	after_n[j] = '\0';
	free(keep_string);
	return (after_n);
}

char	*get_next_line(int fd)
{
	static char	*keep_string;
	char		*result_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keep_string = ft_read(fd, keep_string);
	if (!keep_string)
		return (NULL);
	result_string = ft_get_line(keep_string);
	keep_string = ft_keep_str(keep_string, result_string);
	return (result_string);
}
