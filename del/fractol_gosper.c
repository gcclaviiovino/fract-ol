/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_gosper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:59:33 by liovino           #+#    #+#             */
/*   Updated: 2025/02/10 17:02:17 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	decide_move(int *steps, t_complex d)
{
	if (d.rl_x > d.im_y)
		*steps = d.rl_x;
	else
		*steps = d.im_y;
}
/*
void	gosper_params(t_gosper start, t_gosper end, t_complex *check_point, t_complex *s)
{
	check_point->rl_x = start.x;
	check_point->im_y = start.y;
	if (start.x < end.x)
		s->rl_x = 1;
	else
		s->rl_x = -1;
	if (start.y < end.y)
		s->im_y = 1;
	else
		s->im_y = -1;
	if (fabs(start.y - end.y) < 0.001) 
		s->im_y = 0;
}*/

void	gosper_params(t_gosper start, t_gosper end, t_complex *check_point, t_complex *inc)
{
	check_point->rl_x = start.x;
	check_point->im_y = start.y;
	if (start.x < end.x)
		s->rl_x = 1;
	else
		s->rl_x = -1;
	if (start.y < end.y)
		s->im_y = 1;
	else
		s->im_y = -1;
	if (fabs(start.y - end.y) < 0.001) 
		s->im_y = 0;
}

void	draw_line(t_gosper start, t_gosper end, t_fractal *fractal)
{
	t_complex	check_point;
	t_err		p;
	int			steps;
	t_complex	d;
	t_complex	s;

	p.i = 0;
	steps = 0;
	d.rl_x = fabs(end.x - start.x);
	d.im_y = fabs(end.y - start.y);
	gosper_params(start, end, &check_point, &s);
	decide_move(&steps, d);
	p.main = 2 * d.im_y - d.rl_x;
	while (p.i < steps)
	{
		printf("Drawing pixel at (%f, %f)\n", check_point.rl_x, check_point.im_y);
		show_pixel(check_point, &fractal->image, HOT_PURPLE);
		p.temp = 2 * p.main;
		check_point.rl_x += s.rl_x;
		check_point.im_y += s.im_y;
		p.i ++;
	}
}

void	move(t_gosper *point, int instruction, int step, t_fractal *fractal)
{
	double		rad;
	t_gosper	new_p;
	double		degrees;
	static t_gosper	min;

	min.x = 0;
	min.y = 0;
	degrees = 60;
	if (instruction == 'A' || instruction == 'B')
	{
		rad = (point->angle * PI) / 180.0;
		new_p.x = point->x + step * cos(rad);
		new_p.y = point->y + step * sin(rad);
		ext(new_p, &min);
		point->x = new_p.x - min.x;
		point->y = fmin(min.y, new_p.y);
		draw_line(*point, new_p, fractal);
	}
	else if (instruction == TURN_LEFT)
		point->angle += degrees;
	else if (instruction == TURN_RIGHT)
		point->angle -= degrees;
	if (point->angle >= 360)
		point->angle -= 360;
	else if (point->angle < 0)
		point->angle += 360;
}

void	gosper_def(t_complex point, t_fractal *fractal)
{
	int			i;
	t_gosper	pix;
	char		res[MAX_LEN];

	ft_lsystem(res, "A", fractal->image_def);
	pix.x = point.rl_x;
	pix.y = point.im_y;
	pix.angle = 0;
	i = 0;
	while (res[i] && i <= fractal->image_def)
	{
		move(&pix, res[i], 5, fractal);
		i ++;
	}
}
