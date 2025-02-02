/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:27:44 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:27:45 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_s1;
	unsigned char	*s_s2;

	s_s1 = (unsigned char *)s1;
	s_s2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*s_s1 != *s_s2)
			return ((int)*s_s1 - *s_s2);
		s_s1 ++;
		s_s2 ++;
		n --;
	}
	return (0);
}
