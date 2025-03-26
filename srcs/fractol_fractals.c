/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:15:10 by liovino           #+#    #+#             */
/*   Updated: 2025/03/26 17:36:45 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_def(double x, double y, t_vals *vals, t_fractal *fractal)
{
	vals->z.rl_x = 0.0;
	vals->z.im_y = 0.0;
	vals->c.rl_x = (scaling(x, WIDTH, -2.0, 2.0) * fractal->zoom) \
				+ fractal->shift_x;
	vals->c.im_y = (scaling(y, HEIGHT, 2.0, -2.0) * fractal->zoom) \
				+ fractal->shift_y;
}

void	julia_def(double x, double y, t_vals *vals, t_fractal *fractal)
{
	vals->z.rl_x = (scaling(x, WIDTH, -2.0, 2.0) * fractal->zoom \
				+ fractal->shift_x);
	vals->z.im_y = (scaling(y, HEIGHT, 2.0, -2.0) * fractal->zoom \
				+ fractal->shift_y);
	vals->c.rl_x = fractal->julia_x;
	vals->c.im_y = fractal->julia_y;
}

void	absolute_def(double x, double y, t_vals *vals, t_fractal *fractal)
{
	vals->z.rl_x = 0.0;
	vals->z.im_y = 0.0;
	vals->c.rl_x = fabs(scaling(x, WIDTH, -2.0, 2.0) * \
				fractal->zoom) + fractal->shift_x;
	vals->c.im_y = fabs(scaling(y, HEIGHT, 2.0, -2.0) * \
				fractal->zoom) + fractal->shift_y;
}
