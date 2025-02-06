/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:59:28 by liovino           #+#    #+#             */
/*   Updated: 2025/02/06 17:10:43 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scaling(double num, double o_min, double o_max, double n_min, double n_max)
{
	double	scaled_p;
	
	if (o_min == o_max)
		return (n_min);
	scaled_p = (n_max - n_min) * ((num - o_min) / (o_max - o_min)) + n_min;
	return (scaled_p);
}

t_complex	c_sum(t_complex z_sq, t_complex c)
{
	t_complex	sum;


	sum.real_x = z_sq.real_x + c.real_x;
	sum.imaginary_y = z_sq.imaginary_y + c.imaginary_y;
	return (sum);
}

t_complex	c_square(t_complex z)
{
	t_complex sq;
	
	//complex square = (x^2 - y^2) + 2xyi
	sq.real_x = (z.real_x * z.real_x) - (z.imaginary_y * z.imaginary_y);
	sq.imaginary_y = 2 * (z.real_x * z.imaginary_y);
	return (sq);
}

int		lin_interpol(int start_val, int end_val, double point)
{
	int	inter_val;

	inter_val = start_val + (point * (end_val - start_val));
	return (inter_val);
}

t_colour	ft_itoc(int hex)
{
	t_colour	colour;

	colour.r = (hex >> 16) & 0xFF;
	colour.g = (hex >> 8) & 0xFF;
	colour.b = hex & 0xFF;
	colour.val = hex;
	return (colour);
}