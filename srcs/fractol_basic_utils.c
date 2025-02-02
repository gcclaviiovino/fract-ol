/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_basic_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:02:03 by liovino           #+#    #+#             */
/*   Updated: 2025/02/02 17:22:09 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	def_data(t_fractal *fractal)
{
	fractal->escape_val = 2 * 2;
	fractal->image_def = 50;
	
}

double	ft_atodec(char *str)
{
	int		sign;
	long	integer_p;
	double	decimal_p;
	double	power;

	sign = 1;
	integer_p = 0;
	decimal_p = 0;
	power = 1;
	if (*str++ == '-')
		sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		integer_p = (integer_p * 10) + (*str - '0');
		str ++;
	}
	while (*str)
	{
			if (*str == '.')
				str ++;
			power /= 10;
			decimal_p = decimal_p + (*str - '0') * power;
			str ++;
	}
	return ((integer_p + decimal_p) * sign);
}
