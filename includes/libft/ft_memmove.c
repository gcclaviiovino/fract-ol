/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:41:43 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:28:04 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t			cnt;
	size_t			i;
	unsigned char	*ds;
	unsigned char	*sr;

	cnt = 0;
	i = 1;
	if (!dest || !src)
		return (NULL);
	ds = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (dest > src)
	{
		i = -1;
		ds += count - 1;
		sr += count -1;
	}
	while (cnt < count)
	{
		*ds = *sr;
		ds += i;
		sr += i;
		cnt ++;
	}
	return (dest);
}
