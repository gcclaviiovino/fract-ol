/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:57:25 by liovino           #+#    #+#             */
/*   Updated: 2025/01/16 17:12:18 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	usize(unsigned long int nb, size_t base)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		count ++;
	}
	return (count);
}

char	*ft_uitoa_base(unsigned long int n_l, int base)
{
	int					len;
	char				*str;
	int					remainder;

	len = usize(n_l, base);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n_l == 0)
		str[len - 1] = '0';
	str[len] = '\0';
	while (n_l > 0)
	{
		remainder = (n_l % base);
		if (remainder < 10)
			str[--len] = remainder + '0';
		else
			str[--len] = (remainder - 10) + 'a';
		n_l /= base;
	}
	return (str);
}

char	*ft_case_changer(char *str, char type)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (type == 'x')
			str[i] = ft_tolower(str[i]);
		else
			str[i] = ft_toupper(str[i]);
		i ++;
	}
	ft_putstr_fd(str, 1);
	return (str);
}
