/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_gosper_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:02:33 by liovino           #+#    #+#             */
/*   Updated: 2025/02/13 14:52:00 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	params_init(t_gosper start, t_gosper end, t_complex *d, t_complex *point)
{
	point->rl_x = start.x;
	point->im_y = start.y;
	d->rl_x = fabs(end.x - start.x);
	d->im_y = fabs(end.y - start.y);
//	printf("Params: d.rl_x = %f, d.im_y = %f\n", d->rl_x, d->im_y);
}

void	decide_move(t_complex *s, t_gosper start, t_gosper end)
{
	if (start.x < end.x)
		s->rl_x = 1;
	else
		s->rl_x = -1;
	if (start.y < end.y)
		s->im_y = 1;
	else
		s->im_y = -1;
//	printf("Move step: rl_x = %d, im_y = %d\n", (int)s->rl_x, (int)s->im_y);
}

void	bresenham(t_gosper start, t_gosper end, t_fractal *fractal)
{
	t_complex	d;
	t_complex	point;
	int			err;
	int			err2;
	t_complex	inc;

	params_init(start, end, &d, &point);
	decide_move(&inc, start, end);
	err = d.rl_x - d.im_y;
	while (fabs(point.rl_x - end.x) > 0.5 || fabs(point.im_y - end.y) > 0.5)
	{
		printf("Drawing at: (%.1f, %.1f) | err: %d\n", point.rl_x, point.im_y, err);
		show_pixel(point, &fractal->image, HOT_PURPLE);
//		printf("pixel has been drawn\n");
		err2 = err * 2;
		if (err2 > -d.im_y)
		{
			err -= d.im_y;
			point.rl_x += inc.rl_x;
		}
		if (err2 < d.rl_x)
		{
			err += d.rl_x;
			point.im_y += inc.im_y;
		}
	}
}

void	move(t_gosper *pix, int instruction, int step, t_fractal *fractal)
{
	double		degrees;
	double		rad;
	t_gosper	next;

	degrees = 60.0;
	if (instruction == 'A' || instruction == 'B')
	{
		rad = (pix->angle * PI) / 180.0;
		next.x = pix->x + step * cos(rad);
		next.y = pix->y + step * sin(rad);
		bresenham(*pix, next, fractal);
	}
	else if (instruction == TURN_LEFT)
		pix->angle += degrees;
	else if (instruction == TURN_RIGHT)
		pix->angle -= degrees;
	pix->angle = fmod(pix->angle + 360, 360);
}

void	gosper_def(t_complex point, t_fractal *fractal)
{
	t_gosper	pix;
	char		res[MAX_LEN];
	int			i;

	i = 0;
	pix.x = point.rl_x;
	pix.y = point.im_y;
	pix.angle = 0.0;
	ft_lsystem(res, "A", fractal->image_def);
//	printf("res after: %s\n", res);
	while (res[i] && i < fractal->image_def)
	{
		move(&pix, res[i], 5, fractal); // 5 scelto arbitrariamente
		i ++;
	}
//	printf("exiting function\n");
}