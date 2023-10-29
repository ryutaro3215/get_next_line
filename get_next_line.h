/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:48:30 by rmatsuba          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/26 21:05:24 by rmatsuba         ###   ########.fr       */
=======
/*   Updated: 2023/10/28 23:35:22 by ryutaro3205      ###   ########.fr       */
>>>>>>> 36362d5dffe0c9f4a7008067239673eee6f739b9
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
<<<<<<< HEAD
=======
char	*ft_read(int fd, char *hold_str);
char	*ft_get_line(char *hold_str);
char	*ft_hold(char *hold_str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
>>>>>>> 36362d5dffe0c9f4a7008067239673eee6f739b9

#endif
