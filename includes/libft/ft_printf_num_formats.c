/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_formats.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:05:44 by liovino           #+#    #+#             */
/*   Updated: 2025/01/16 17:13:05 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(int n)
{
	int		i;
	char	*str;

	ft_putnbr_fd(n, 1);
	str = ft_itoa(n);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	print_unum(unsigned int n)
{
	int		i;
	char	*str;

	str = ft_uitoa_base(n, 10);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	print_hex(unsigned int num, char arg)
{
	char	*res;
	int		len;

	res = ft_uitoa_base(num, 16);
	ft_case_changer(res, arg);
	len = ft_strlen(res);
	free(res);
	return (len);
}
