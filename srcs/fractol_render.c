/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:42:53 by liovino           #+#    #+#             */
/*   Updated: 2025/03/26 17:36:39 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_pixel(int x, int y, t_image *img, int colour)
{
	int	move;

	if (!img || !img->pix_ptr)
		return ;
	move = ((y * img->line_len) + (x * (img->bytes_pp / 8)));
	*(unsigned int *)(img->pix_ptr + move) = colour;
}

void	manage_pixel(double x, double y, t_fractal *fractal)
{
	t_vals		vals;
	int			i;
	int			colour;

	i = 0;
	if (ft_strncmp(fractal->name, "Mandelbrot", 10) == 0)
		mandel_def(x, y, &vals, fractal);
	else if (ft_strncmp(fractal->name, "Julia", 5) == 0)
		julia_def(x, y, &vals, fractal);
	else if (ft_strncmp(fractal->name, "absolute", 8) == 0)
		absolute_def(x, y, &vals, fractal);
	while (i < fractal->image_def)
	{
		vals.z = c_sum(c_square(vals.z), vals.c);
		if (((vals.z.rl_x * vals.z.rl_x) + (vals.z.im_y * vals.z.im_y)) \
				> fractal->escape_val)
		{
			colour = get_colour(vals.z, i, fractal);
			show_pixel(x, y, &fractal->image, colour);
			return ;
		}
		i ++;
	}
	show_pixel(x, y, &fractal->image, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	double	x;
	double	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			manage_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connect, fractal->mlx_window, \
							fractal->image.image_ptr, 0, 0);
}
