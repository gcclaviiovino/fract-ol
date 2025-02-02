/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:48:27 by liovino           #+#    #+#             */
/*   Updated: 2025/02/02 17:22:48 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && (ft_strncmp(argv[1], "Mandelbrot", 10)) == 0) \
		|| (argc == 4 && (ft_strncmp(argv[1], "Julia", 5)) == 0))
	{
		fractal.name = argv[1];
		if (argc == 4)
		{
			fractal.julia_x = ft_atodec(argv[2]);
			fractal.julia_y = ft_atodec(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connect);
	}
	else
	{
		ft_putstr_fd(ERROR_MESS, 2);
		exit(EXIT_FAILURE);
	}
}
