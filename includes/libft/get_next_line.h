/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:41:03 by liovino           #+#    #+#             */
/*   Updated: 2025/01/10 23:16:21 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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