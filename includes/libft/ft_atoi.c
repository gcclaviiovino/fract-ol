/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:50:02 by liovino           #+#    #+#             */
/*   Updated: 2024/12/15 15:32:12 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	if (!str)
		return (0);
	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (-2147483648);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i ++;
	}
	return (res * sign);
}

// int	main(void)
// {
// 	char	*str = "\n\n\n  -46\b9 \n5d6";

// 	printf("mio: %d\n", ft_atoi(str));
// 	printf("suo: %d\n", atoi(str));
// }