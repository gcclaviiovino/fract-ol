/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:17:57 by liovino           #+#    #+#             */
/*   Updated: 2025/01/11 18:01:24 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

# ifndef MAX_FD
#  define MAX_FD 1048576
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*next_line(char *buff);
char	*find_line(int fd);
char	*ft_strchr(char *str, char c);
char	*ft_strchrcpy(char *dest, char *src, char c);
void	*ft_calloc(size_t nelem, size_t elsize);
char	*ft_strdup(char *str);

#endif