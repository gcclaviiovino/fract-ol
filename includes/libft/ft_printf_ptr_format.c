/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:46:10 by liovino           #+#    #+#             */
/*   Updated: 2025/01/16 16:56:03 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prefix(char **pointer)
{
	char	*new_pointer;

	new_pointer = ft_strjoin("0x", *pointer);
	if (!new_pointer)
	{
		free(new_pointer);
		free(*pointer);
		pointer = NULL;
		return (0);
	}
	free(*pointer);
	*pointer = new_pointer;
	return (0);
}

int	fill_ptr(char **pointer, uintptr_t num)
{
	char	*add;
	int		count;
	char	*new;

	count = prefix(pointer);
	add = ft_uitoa_base(num, 16);
	if (!add)
	{
		free(add);
		free(*pointer);
		return (0);
	}
	new = ft_strjoin(*pointer, add);
	free(add);
	free(*pointer);
	if (!new)
	{
		free(new);
		return (0);
	}
	*pointer = new;
	count += ft_strlen(*pointer);
	return (count);
}

int	print_point(void *pointer)
{
	int			len;
	uintptr_t	address;
	char		*out;

	address = (uintptr_t)pointer;
	len = 0;
	if (address == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (ft_strlen("(nil)"));
	}
	out = (char *) malloc(sizeof(char) * 1);
	if (!out)
		return (0);
	out[0] = '\0';
	len += fill_ptr(&out, address);
	ft_putstr_fd(out, 1);
	free(out);

	return (len);
}
