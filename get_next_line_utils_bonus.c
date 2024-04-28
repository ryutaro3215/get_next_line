/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:55:55 by rmatsuba          #+#    #+#             */
/*   Updated: 2024/04/29 01:05:37 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
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
	{
		str1 = (char *)malloc(1 * sizeof(char));
		if (!str1)
			return (NULL);
		str1[0] = '\0';
	}
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
	free(str1);
	return (result_str);
}

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

char	*check_end(char *keep_string, int i)
{
	char	*line_string;

	if (keep_string[i] == '\0')
		line_string = (char *)malloc(sizeof(char) * (i + 1));
	else
		line_string = (char *)malloc(sizeof(char) * (i + 2));
	if (!line_string)
		return (NULL);
	return (line_string);
}
