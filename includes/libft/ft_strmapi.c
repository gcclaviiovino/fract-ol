/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:54:28 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:30:15 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*f_str;
	int				len;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	f_str = (char *) malloc(sizeof(char) * (len + 1));
	if (!f_str)
		return (NULL);
	while (s[i] != '\0')
	{
		f_str[i] = (*f)(i, s[i]);
		i ++;
	}
	f_str[i] = '\0';
	return (f_str);
}
