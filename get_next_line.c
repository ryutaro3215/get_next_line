/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:44:14 by rmatsuba          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/26 21:14:50 by rmatsuba         ###   ########.fr       */
=======
/*   Updated: 2023/10/28 23:37:34 by ryutaro3205      ###   ########.fr       */
>>>>>>> 36362d5dffe0c9f4a7008067239673eee6f739b9
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *hold_str);
char	*ft_get_line(char *hold_str);
char	*ft_hold(char *hold_str);

char	*get_next_line(int fd)
{
<<<<<<< HEAD
	int		read_len;
	char	*buffer;
	static 

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_len = read(fd, buffer, BUFFER_SIZE);


}
=======
	char		*result_str;
	static char	*hold_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	hold_str = ft_read(fd, hold_str);
	if (!hold_str)
		return (NULL);
	result_str = ft_get_line(hold_str);
	hold_str = ft_hold(hold_str);
	return (result_str);
}

char	*ft_read(int fd, char *hold_str)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(hold_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		hold_str = ft_strjoin(hold_str, buffer);
	}
	free(buffer);
	return (hold_str);
}

char	*ft_hold(char *hold_str)
{
	int	i;
	int	j;
	char	*after_n;

	i = 0;
	j = 0;
	while (hold_str[i] != '\0' && hold_str[i] != '\n')
		i++;
	if (hold_str == NULL)
	{
		free(hold_str);
		return (NULL);
	}
	after_n = (char *)malloc(sizeof(char) * (ft_strlen(hold_str) - i + 1));
	if (!after_n)
		return (NULL);
	i++;
	while (hold_str[i] != '\0')
		after_n[j++] = hold_str[i++];
	after_n[j] = '\0';
	free(hold_str);
	return (after_n);
}

char	*ft_get_line(char *hold_str)
{
	int		i;
	char	*line_str;

	i = 0;
	if (!hold_str)
		return (NULL);
	while (hold_str[i] != '\0' && hold_str[i] != '\n')
		i++;
	line_str = (char *)malloc(sizeof(char) * (i + 2));
	if (!line_str)
		return (NULL);
	while (hold_str[i] != '\0'&& hold_str[i] != '\n')
	{
		line_str[i] = hold_str[i];
		i++;
	}
	if (hold_str[i] == '\n')
	{
		line_str[i] = hold_str[i];
		i++;
	}
	line_str[i] = '\0';
	return (line_str);
}
>>>>>>> 36362d5dffe0c9f4a7008067239673eee6f739b9
