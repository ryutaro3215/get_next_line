/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:44:07 by rmatsuba          #+#    #+#             */
/*   Updated: 2023/10/29 16:41:07 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
