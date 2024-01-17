/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:44:14 by rmatsuba          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/23 19:22:27 by ryutaro3205      ###   ########.fr       */
=======
/*   Updated: 2023/12/05 14:28:05 by rmatsuba         ###   ########.fr       */
>>>>>>> 1903a5d19fa3fdb8697e617fb9d28b4b75be54a7
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
	if (keep_string[i] == '\0')
		line_string = (char *)malloc(sizeof(char) * (i + 1));
	else
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
		line_string[i] = keep_string[i];
	line_string[++i] = '\0';
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

<<<<<<< HEAD
int	main(void)
{
	char	*str;
	int	fd;

	fd = open("sample.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("result : %s", str);
	return (0);
}
=======
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

// int	main(void)
// {
// 	char	*str1;
// 	// char	*str2;
// 	int	fd1;
// 	// int	fd2;
// 	int	counter;

// 	counter = 0;
// 	fd1 = open("sample.txt", O_RDONLY);
// 	// fd2 = open("test.txt", O_RDONLY);
// 	str1 = get_next_line(fd1);
// 	// str2 = get_next_line(fd2);
// 	while (str1)
// 	{
// 		printf("%s", str1);
// 		free(str1);
// 		str1 = get_next_line(fd1);
// 		if (str1 == NULL)
// 		{
// 			printf("%s", str1);
// 			break ;
// 		}
// 	}
// 	// while (str2)
// 	// {
// 	// 	printf("%s", str2);
// 	// 	free(str2);
// 	// 	str2 = get_next_line(fd2);
// 	// 	if (str2 == NULL)
// 	// 		{
// 	// 			printf("%s", str2);
// 	// 			break ;
// 	// 		}
// 	// }
// 	// printf("%s", str1);
// 	// printf("%s", str2);
// 	return (0);
// }
// #include <libc.h>
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
>>>>>>> 1903a5d19fa3fdb8697e617fb9d28b4b75be54a7
