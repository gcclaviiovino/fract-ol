/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:15:10 by liovino           #+#    #+#             */
/*   Updated: 2025/02/02 19:54:33 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_def(double x, double y, t_complex *z, t_complex *c, t_fractal *fractal)
{
	z->real_x = 0.0;
	z->imaginary_y = 0.0;
	c->real_x = (scaling(x,  0, WIDTH, -2.0, 2.0) * fractal->zoom) + fractal->shift_x;
	c->imaginary_y = (scaling(y,  0, HEIGHT, 2.0, -2.0) * fractal->zoom) + fractal->shift_y;
}

void	julia_def(double x, double y, t_complex *z, t_complex *c, t_fractal *fractal)
{
	z->real_x = (scaling(x, 0, WIDTH, -2.0, 2.0) * fractal->zoom + fractal->shift_x);
	z->imaginary_y = (scaling(y, 0, HEIGHT, 2.0, -2.0) * fractal->zoom + fractal->shift_y);
	c->real_x = fractal->julia_x;
	c->imaginary_y = fractal->julia_y;
}
/*
void	gosper_def()
{
	
}*/