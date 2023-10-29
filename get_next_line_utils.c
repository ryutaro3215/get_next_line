/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:44:07 by rmatsuba          #+#    #+#             */
/*   Updated: 2023/10/29 11:48:59 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	w;

	w = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == w)
			return ((char *)s);
		s++;
	}
	if (w == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat_str;
	int		j;
	int		i;
	int		s1_len;
	int		s2_len;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concat_str = (char *)malloc(s1_len + s2_len + 1);
	if (concat_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
		concat_str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		concat_str[j++] = s2[i++];
	concat_str[j] = '\0';
	return (concat_str);
}
