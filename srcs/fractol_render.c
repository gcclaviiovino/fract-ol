/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:42:53 by liovino           #+#    #+#             */
/*   Updated: 2025/02/06 19:22:45 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_pixel(int x, int y, t_image *img, int colour) //better-rendering version of mlx_pixel_put()
{
	int	move;

	if (!img || !img->pix_ptr)
		return ;
	move = ((y * img->line_len) + (x * (img->bytes_pp / 8)));
	*(unsigned int *)(img->pix_ptr + move) = colour;
}

void	manage_pixel(double x, double y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	if (ft_strncmp(fractal->name, "Mandelbrot", 10) == 0)
		mandelbrot_def(x, y, &z, &c, fractal);
	else if (ft_strncmp(fractal->name, "Julia", 5) == 0)
		julia_def(x, y, &z, &c, fractal);
	while (i < fractal->image_def)
	{
		z = c_sum(c_square(z), c);
		if (((z.real_x * z.real_x) + (z.imaginary_y * z.imaginary_y)) > fractal->escape_val)
		{
			colour = get_colour(z, i, fractal);
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
	mlx_put_image_to_window(fractal->mlx_connect, fractal->mlx_window, fractal->image.image_ptr, 0, 0);
}