/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:15:10 by liovino           #+#    #+#             */
/*   Updated: 2025/02/02 17:13:09 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
void	choose_fractal(t_fractal *fractal, double x, double y, t_complex z, t_complex c)
{
	if (ft_strncmp(fractal->name, "Mandelbrot", 10) == 0)
		mandelbrot_def(x, y, &z, &c);
	else if (ft_strncmp(fractal->name, "Julia", 5) == 0)
		julia_def(x, y, &z, &c, fractal);
//	else if (fractal.name == "Gosper")
//		gosper_def();
}*/


void	mandelbrot_def(double x, double y, t_complex *z, t_complex *c)
{
	z->real_x = 0.0;
	z->imaginary_y = 0.0;
	c->real_x = scaling(x,  0, WIDTH, -2.0, 2.0);
	c->imaginary_y = scaling(y,  0, HEIGHT, 2.0, -2.0);
}

void	julia_def(double x, double y, t_complex *z, t_complex *c, t_fractal *fractal)
{
	z->real_x = scaling(x, 0, WIDTH, -2.0, 2.0);
	z->imaginary_y = scaling(y, 0, HEIGHT, 2.0, -2.0);
	c->real_x = fractal->julia_x;
	c->imaginary_y = fractal->julia_y;
}
/*
void	gosper_def()
{
	
}*/