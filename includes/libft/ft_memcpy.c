/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:27:57 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 16:07:10 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ds;
	const unsigned char	*sr;
	size_t				i;

	i = 0;
	if (!dest || !src)
		return (dest);
	ds = (unsigned char *)dest;
	sr = (const unsigned char *)src;
	if (dest != src)
	{
		while (i < n)
		{
			ds[i] = sr[i];
			i ++;
		}
	}
	return (dest);
}
// int	main(void)
// {
// 	char dest[100];
// 	ft_memset(dest, 'A', 100);
// 	printf("str copiata: %s\n", (char *)ft_memcpy(dest , "cocou", 0));
// }