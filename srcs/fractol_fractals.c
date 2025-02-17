/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:15:10 by liovino           #+#    #+#             */
/*   Updated: 2025/02/17 14:06:22 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_def(double x, double y, t_complex *z, t_complex *c, t_fractal *fractal)
{
	z->rl_x = 0.0;
	z->im_y = 0.0;
	c->rl_x = (scaling(x, WIDTH, -2.0, 2.0) * fractal->zoom) + fractal->shift_x;
	c->im_y = (scaling(y, HEIGHT, 2.0, -2.0) * fractal->zoom) + fractal->shift_y;
}

void	julia_def(double x, double y, t_complex *z, t_complex *c, t_fractal *fractal)
{
	z->rl_x = (scaling(x, WIDTH, -2.0, 2.0) * fractal->zoom + fractal->shift_x);
	z->im_y = (scaling(y, HEIGHT, 2.0, -2.0) * fractal->zoom + fractal->shift_y);
	c->rl_x = fractal->julia_x;
	c->im_y = fractal->julia_y;
}
