/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:43:41 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:29:56 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <bsd/string.h>
// #include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	i_dst;
	size_t	i_src;

	i = 0;
	if (!dest)
		return (0);
	i_dst = ft_strlen(dest);
	i_src = ft_strlen(src);
	if (size <= i_dst)
		return (size + i_src);
	while (src[i] != '\0' && (i_dst + i) < size - 1)
	{
		dest[i + i_dst] = src[i];
		i ++;
	}
	dest[i + i_dst] = '\0';
	return (i_dst + i_src);
}

// int	main(void)
// {
// 	char	s1[14] = "a";

// 	printf("mio: %zu\n", ft_strlcat(s1, "lorem", 15));
// 	printf("suo: %zu\n", strlcat(s1, "lorem", 15));
// }