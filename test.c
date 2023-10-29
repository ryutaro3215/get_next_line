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

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*result_str;

	i = -1;
	j = 0;
	if (!str1)
		str1 = "";
	if (!str1 || !str2)
		return (NULL);
	result_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!result_str)
		return (NULL);
	while (str1[++i] != '\0')
		result_str[i] = str1[i];
	while (str2[j] != '\0')
		result_str[i++] = str2[j++];
	result_str[i] = '\0';
	return (result_str);
}

char	*ft_read(int fd, char *keep_string)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
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
	if (!keep_string)
		return (NULL);
	while (keep_string[i] != '\0' && keep_string[i] != '\n')
		i++;
	line_string = (char *)malloc(sizeof(char) * (i + 2));
	if (!line_string)
		return (NULL);
	i = 0;
	while (keep_string[i] != '\0' && keep_string[i] != '\n')
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
	int	i;
	int	j;
	char	*after_n;

	i = 0;
	j = 0;
	if (!keep_string)
	{
		free(keep_string);
		return (NULL);
	}
	while (keep_string[i] != '\0' && keep_string[i] != '\n')
		i++;
	after_n = malloc(sizeof(char) * (ft_strlen(keep_string) - i + 1));
	if (!after_n)
		return (NULL);
	i++;
	while (keep_string[i] != '\0')
		after_n[j++] = keep_string[i++];
	after_n[j] = '\0';
	free(keep_string);
	return (after_n);
}

int	main(void)
{
	static char	*str;
	int		fd;
	char	*result_get_line;
	char	*after_n;

	fd = open("sample.txt", O_RDONLY);
	str = ft_read(fd, str);
	printf("result before ft_get_line : %s\n", str);
	result_get_line = ft_get_line(str);
	printf("result after ft_get_line : %s\n", result_get_line);
	after_n = ft_keep_str(str);
	printf("result after ft_keep_str : %s\n", after_n);
	return (0);
}
