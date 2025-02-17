/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:42:52 by liovino           #+#    #+#             */
/*   Updated: 2025/02/17 13:53:25 by liovino          ###   ########.fr       */
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

int	manage_some(int key, t_fractal *fractal)
{
	if (key == XK_Escape)
		manage_exit(fractal);
	if (key == XK_Left)
		fractal->shift_x -= (fractal->max.rl_x - fractal->min.rl_x) \
							* 0.05;
	else if (key == XK_Up)
		fractal->shift_y -= (fractal->max.im_y - fractal->min.im_y) \
							* 0.05;
	else if (key == XK_Right)
		fractal->shift_x += (fractal->max.rl_x - fractal->min.rl_x) \
							* 0.05;
	else if (key == XK_Down)
		fractal->shift_y += (fractal->max.im_y - fractal->min.im_y) \
							* 0.05;
	else if (key == XK_plus)
		fractal->image_def += 10;
	else if (key == XK_minus)
		fractal->image_def -= 10;
	fractal_render(fractal);
	return (0);
}

int	manage_more(int key, t_fractal *fractal)
{
	bool	redraw;

	redraw = 0;
	if (key == 65288)
		fractal->motion = !fractal->motion;
	else if (key == 32)
	{
		fractal->smooth = !fractal->smooth;
		redraw = 1;
	}
	else if (key == XK_Tab)
	{
		if (fractal->palette.val < 2)
			fractal->palette.val += 1;
		else
			fractal->palette.val = 1;
		palette_def(&fractal->palette, fractal);
		redraw = 1;
	}
	if (redraw)
		fractal_render(fractal);
	return (0);
}

int	manage_mouse(int button, int x, int y, t_fractal *fractal)
{
	double		zm;
	t_complex	mouse;
//	t_complex	d;

	zm = 0;
//	mouse.rl_x = scaling(x, WIDTH, fractal->min.rl_x, fractal->max.rl_x);
//	mouse.im_y = scaling(y, HEIGHT, fractal->min.im_y, fractal->max.im_y);
	mouse.rl_x = x;
	mouse.im_y = y;
if (button == Button5)
		zm = 1.05;
	else if (button == Button4)
		zm = 0.95;
	else
		return (0);
	fractal->min.rl_x = mouse.rl_x + (fractal->min.rl_x - mouse.rl_x) * zm;
	fractal->max.rl_x = mouse.rl_x + (fractal->max.rl_x - mouse.rl_x) * zm;
	fractal->min.im_y = mouse.im_y + (fractal->min.im_y - mouse.im_y) * zm;
	fractal->max.im_y = mouse.im_y + (fractal->max.im_y - mouse.im_y) * zm;
	fractal->zoom *= zm;
	fractal_render(fractal);
	return (0);
}

int	manage_track(int x, int y, t_fractal *fractal)
{
	if (fractal->motion)
	{
		fractal->julia_x = (scaling(x, WIDTH, fractal->min.rl_x, \
				fractal->max.rl_x) * fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (scaling(y, HEIGHT, fractal->min.im_y, \
				fractal->max.im_y) * fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
