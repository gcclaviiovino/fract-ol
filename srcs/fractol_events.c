/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:42:52 by liovino           #+#    #+#             */
/*   Updated: 2025/02/06 20:04:01 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	manage_exit(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connect, fractal->image.image_ptr);
	mlx_destroy_window(fractal->mlx_connect, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connect);
	free(fractal->mlx_connect);
	exit(EXIT_SUCCESS);
}

int	manage_key(int key, t_fractal *fractal)
{
	if (key == XK_Escape)
		manage_exit(fractal);
	if (key == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (key == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (key == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (key == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (key == XK_plus)
		fractal->image_def += 10;
	else if (key == XK_minus)
		fractal->image_def -= 10;
	else if (key == XK_Tab)
	{
		if (fractal->palette.val < 2)
			fractal->palette.val += 1;
		else
			fractal->palette.val = 1;
		palette_def(&fractal->palette, fractal);
	}
	fractal_render(fractal);
	return (0);
}

int	manage_mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;

	if (button == Button5)
		fractal->zoom *= 0.95;
	else if (button == Button4)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return(0);
}

int	manage_track(int x, int y, t_fractal *fractal)
{
	fractal->julia_x = (scaling(x,  0, WIDTH, -2.0, 2.0) * fractal->zoom) + fractal->shift_x;
	fractal->julia_y = (scaling(y,  0, HEIGHT, 2.0, -2.0) * fractal->zoom) + fractal->shift_y;
	fractal_render(fractal);
	return (0);
}