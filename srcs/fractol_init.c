/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:15:18 by liovino           #+#    #+#             */
/*   Updated: 2025/02/02 19:05:26 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_err(void)
{
	perror("Sorry, allocation failed :(");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connect = mlx_init();
	if (!fractal->mlx_connect)
		malloc_err();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connect, WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_err();
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connect, WIDTH, HEIGHT);
	if (!fractal->image.image_ptr)
	{
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_err();
	}
	fractal->image.pix_ptr = mlx_get_data_addr(fractal->image.image_ptr, &fractal->image.bytes_pp, &fractal->image.line_len, &fractal->image.endian);
	events_init(fractal);
	def_data(fractal);
}
