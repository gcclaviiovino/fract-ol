/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:19:33 by liovino           #+#    #+#             */
/*   Updated: 2025/01/11 16:19:35 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str ++;
	}
	return (NULL);
}

char	*ft_strchrcpy(char *dest, char *src, char c)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] != c)
	{
		dest[i] = src[i];
		i ++;
	}
	if (c != '\0')
	{
		dest[i] = c;
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		l_1;
	int		l_2;
	char	*superstr;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	l_1 = ft_strlen(s1);
	l_2 = ft_strlen(s2);
	superstr = (char *) malloc(sizeof(char) * ((l_1 + l_2) + 1));
	if (!superstr)
		return (NULL);
	while (s1[++i] != '\0')
		superstr[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		superstr[l_1 + i] = s2[i];
	superstr[l_1 + i] = '\0';
	free(s1);
	return (superstr);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		len;

	len = 0;
	while (str[len])
		len ++;
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strchrcpy(dest, str, '\0');
	return (dest);
}
