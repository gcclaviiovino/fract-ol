/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:40:17 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:31:31 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(long long int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count ++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count ++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	n_l;

	n_l = n;
	len = size(n_l);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n_l == 0)
		str[len - 1] = '0';
	if (n_l < 0)
	{
		str[0] = '-';
		n_l = -n_l;
	}
	str[len] = '\0';
	len --;
	while (n_l > 0)
	{
		str[len] = (n_l % 10) + '0';
		n_l = n_l / 10;
		len --;
	}
	return (str);
}
/*
int	main(void)
{
	char	*str;

	str = ft_itoa(-2147483648);
	printf("%s", str);
}*/
