/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sierpinski.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:54:31 by liovino           #+#    #+#             */
/*   Updated: 2025/02/17 09:01:21 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	lcg_gen(unsigned int *num)
{
	*num = (*num * 1103515245 + 12345) & 0x7FFFFFFF;
	return (*num);
}

void	sierp_def(t_fractal *fractal)
{
	static bool			init;
	static t_complex	vertices[3];
	static t_complex	current_p;
	static unsigned int	seed;
	t_random			random;

	fractal->smooth = 0;
	random.i = -1;
	seed = 42;
	if (!init)
	{
		vertices[0] = (t_complex){WIDTH / 2.0, 50};
		vertices[1] = (t_complex){50, HEIGHT - 50};
		vertices[2] = (t_complex){WIDTH / 2.0, HEIGHT - 50};
		current_p = (t_complex){WIDTH / 2.0, HEIGHT / 2.0};
		init = 1;
	}
	while (++random.i < fractal->image_def)
	{
		random.new_index = lcg_gen(&seed) % 3;
		current_p.rl_x = (current_p.rl_x + vertices[random.new_index].rl_x) / 2.0;
		current_p.im_y = (current_p.im_y + vertices[random.new_index].im_y) / 2.0;
		show_pixel(current_p, &fractal->image, WHITE);
	}
}
