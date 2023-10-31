#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
// size_t	ft_strlen(char *str)
// {
// 	size_t	len;

// 	len = 0;
// 	while (str[len] != '\0')
// 		len++;
// 	return (len);
// }

// char	*ft_strchr(char *str, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (str == NULL)
// 		return (NULL);
// 	if (c == '\0')
// 		return ((char *)&str[ft_strlen(str)]);
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == (char)c)
// 			return ((char *)&str[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

// char	*ft_strjoin(char *str1, char *str2)
// {
// 	int		i;
// 	int		j;
// 	char	*result_str;

// 	i = -1;
// 	j = 0;
// 	if (!str1)
// 		str1 = "";
// 	if (!str1 || !str2)
// 		return (NULL);
// 	result_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
// 	if (!result_str)
// 		return (NULL);
// 	while (str1[++i] != '\0')
// 		result_str[i] = str1[i];
// 	while (str2[j] != '\0')
// 		result_str[i++] = str2[j++];
// 	result_str[i] = '\0';
// 	return (result_str);
// }

// char	*ft_read(int fd, char *keep_string)
// {
// 	char	*buffer;
// 	int		read_bytes;

// 	read_bytes = 1;
// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (buffer == NULL)
// 		return (NULL);
// 	while (!ft_strchr(keep_string, '\n') && read_bytes != 0)
// 	{
// 		read_bytes = read(fd, buffer, BUFFER_SIZE);
// 		if (read_bytes == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[read_bytes] = '\0';
// 		keep_string = ft_strjoin(keep_string, buffer);
// 	}
// 	free(buffer);
// 	return (keep_string);
// }

int	main(void)
{
	char	*str[50];
	int		read_bytes;
	int		fd;

	// char	*result_get_line;
	// char	*after_n;

	fd = open("sample.txt", O_RDONLY);
	read_bytes = read(fd, str[30], BUFFER_SIZE);
	printf("return : %d", read_bytes);
	return (0);
}
