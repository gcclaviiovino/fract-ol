/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_grading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:48:29 by liovino           #+#    #+#             */
/*   Updated: 2025/02/17 14:02:36 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colour	blend(t_colour base_c, t_colour next_c, double inter_val)
{
	t_colour res_c;
	
	if (base_c.val == next_c.val)
		return (base_c);
	res_c.r = lin_interpol(base_c.r, next_c.r, inter_val);
	res_c.g = lin_interpol(base_c.g, next_c.g, inter_val);
	res_c.b = lin_interpol(base_c.b, next_c.b, inter_val);
	res_c.val = (res_c.r << 16) | (res_c.g << 8) | res_c.b;
//	printf("Base: #%02X%02X%02X, Next: #%02X%02X%02X, inter_val: %.2f -> Result: #%02X%02X%02X\n", base_c.r, base_c.g, base_c.b, next_c.r, next_c.g, next_c.b, inter_val, res_c.r, res_c.g, res_c.b);
//	printf("val: %X\n", res_c.val);
	return (res_c);
}

t_colour	colour_render(int i, t_palette *palette, t_fractal *fractal)
{
	double		i_norm;
	int			index;
	double		i_step;
	double		keep_i;
	int			steps;

	i_norm = (double)i / (double)fractal->image_def;
	steps = (palette->tot - 1);
	keep_i = (i_norm * steps);
	index = (int)(keep_i);
	i_step = (keep_i - index);
	return (blend(ft_itoc(palette->colours[index]), ft_itoc(palette->colours[index + 1]), i_step));
}

t_colour	smooth_log(t_complex z, int i, t_fractal *fractal)
{
	double	zn;
	double	nu;
	double smooth_i;

	zn = (log((z.rl_x * z.rl_x) + (z.im_y * z.im_y)) / 2.0f);
	nu = (log(zn / log(2)) / log(2));
	smooth_i = i + 1 - nu;
	return (colour_render((int)smooth_i, &fractal->palette, fractal));
}

int		get_colour(t_complex z, int i, t_fractal *fractal)
{
	t_colour f_colour;

	if (fractal->smooth)
		f_colour = smooth_log(z, i, fractal);
	else
		f_colour = colour_render(i, &fractal->palette, fractal);
	return (f_colour.val);
}