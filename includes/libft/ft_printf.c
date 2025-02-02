/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:40:09 by liovino           #+#    #+#             */
/*   Updated: 2025/01/16 17:02:36 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_me(va_list args, const char arg)
{
	int	count;

	count = 0;
	if (arg == '%')
		count += print_c('%');
	else if (arg == 'c')
		count += print_c(va_arg(args, int));
	else if (arg == 's')
		count += print_str(va_arg(args, char *));
	else if (arg == 'p')
		count += print_point(va_arg(args, void *));
	else if (arg == 'd' || arg == 'i')
		count += print_num(va_arg(args, int));
	else if (arg == 'u')
		count += print_unum(va_arg(args, unsigned int));
	else if (arg == 'x' || arg == 'X')
		count += print_hex(va_arg(args, unsigned int), arg);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += print_me(args, str[i + 1]);
			i ++;
		}
		else
			len += print_c(str[i]);
		i ++;
	}
	return (len);
}
