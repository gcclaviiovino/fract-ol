/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:44:50 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:30:32 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	i2;

	i = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		i2 = 0;
		if (str[i] == to_find[i2])
		{
			while ((str[i + i2] == to_find[i2]) && (i + i2) < n \
					&& (str[i + i2] && to_find[i2]))
			{
				if (to_find[i2 + 1] == '\0')
					return ((char *)&str[i]);
				i2 ++;
			}
		}
		i ++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("mio: %s\n", ft_strnstr("", "ipsumm", 30));
	printf("suo: %s\n", strnstr("", "ipsumm", 30));
}
*/