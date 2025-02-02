/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:52:56 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:28:32 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		num;
	long int	n_l;

	n_l = n;
	if (n_l < 0)
	{
		write(fd, "-", 1);
		n_l = -n_l;
	}
	if (n_l > 9)
	{
		ft_putnbr_fd(n_l / 10, fd);
		n_l = n_l % 10;
	}
	num = n_l + '0';
	ft_putchar_fd(num, fd);
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
}*/
