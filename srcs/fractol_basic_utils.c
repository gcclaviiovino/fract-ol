/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_basic_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:02:03 by liovino           #+#    #+#             */
/*   Updated: 2025/03/26 17:37:51 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	def_data(t_fractal *fractal)
{
	fractal->escape_val = 2 * 2;
	fractal->image_def = 50;
	fractal->min.rl_x = -2.0;
	fractal->max.rl_x = 2.0;
	fractal->min.im_y = 2.0;
	fractal->max.im_y = -2.0;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;
	fractal->smooth = 1;
	fractal->motion = 0;
	fractal->palette.val = 1;
	palette_def(&fractal->palette, fractal);
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, manage_key, \
			fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, \
			manage_mouse, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, \
			manage_exit, fractal);
	if (ft_strncmp(fractal->name, "Julia", 5) == 0)
		mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask, \
				manage_track, fractal);
}

double	ft_atodec(char *str)
{
	int		sign;
	long	integer_p;
	double	decimal_p;
	double	power;

	sign = 1;
	integer_p = 0;
	decimal_p = 0;
	power = 1;
	if (*str++ == '-')
		sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		integer_p = (integer_p * 10) + (*str - '0');
		str ++;
	}
	while (*str)
	{
		if (*str == '.')
			str ++;
		power /= 10;
		decimal_p = decimal_p + (*str - '0') * power;
		str ++;
	}
	return ((integer_p + decimal_p) * sign);
}

void	palette_def(t_palette *palette, t_fractal *fractal)
{
	static t_palette	array[2];

	array[0] = (t_palette){1, 6, {0xF6EC0E, 0xF09530, 0xDA507A, 0xC34B8A, \
				0xB34F9A, 0xD1204A}};
	array[1] = (t_palette){2, 6, {0x3E2F20, 0x705D38, 0xA08A5E, 0xC4B07A, \
				0xE0D4A3, 0xF5EED0}};
	if (fractal->palette.val == 1)
		*palette = array[0];
	else if (fractal->palette.val == 2)
		*palette = array[1];
	return ;
}

int	manage_key(int key, t_fractal *fractal)
{
	if (key == 65288 || key == 32 || key == XK_Tab)
		manage_more(key, fractal);
	else
		manage_some(key, fractal);
	return (0);
}
