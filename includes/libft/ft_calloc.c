/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:38:51 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:31:59 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*mem;

	if (nelem != 0 && elsize > (SIZE_MAX / nelem))
		return (NULL);
	mem = (void *) malloc(elsize * nelem);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (elsize * nelem));
	return (mem);
}
