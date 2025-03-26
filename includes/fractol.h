/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:00:07 by liovino           #+#    #+#             */
/*   Updated: 2025/03/26 17:36:09 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ERROR_MESS "Problem with request...Please enter \n\t\"./fractol Mandelbrot\" \
					or \n\t\"./fractol Julia <value_x> <value_y>\" \
					or \n\t\"./fractol absolute\""

# define WIDTH 600
# define HEIGHT 600
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define DEEP_BROWN 0x3E2F20
# define WARM_CREAM 0xF5EED0
# define YELLOWISH 0xF6EC0E
# define LILAC 0x8E5BCE

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_complex
{
	double	rl_x;
	double	im_y;
}	t_complex;

typedef struct s_image
{
	void	*image_ptr;
	char	*pix_ptr;
	int		bytes_pp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_palette
{
	int		val;
	uint8_t	tot;
	int		colours[6];
}	t_palette;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connect;
	void		*mlx_window;
	t_image		image;
	double		escape_val;
	int			image_def;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
	t_palette	palette;
	bool		smooth;
	bool		motion;
	t_complex	max;
	t_complex	min;
}	t_fractal;

typedef struct s_colour
{
	int		val;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_colour;

typedef struct s_vals
{
	t_complex	z;
	t_complex	c;
}	t_vals;

void		fractal_init(t_fractal *fractal);
void		malloc_err(void);
double		scaling(double num, double o_max, double n_min, double n_max);
t_complex	c_sum(t_complex z, t_complex z_sq);
t_complex	c_square(t_complex z);
void		fractal_render(t_fractal *fractal);
void		manage_pixel(double x, double y, t_fractal *fractal);
void		show_pixel(int x, int y, t_image *img, int colour);
void		def_data(t_fractal *fractal);
void		mandel_def(double x, double y, t_vals *vals, t_fractal *fractal);
void		julia_def(double x, double y, t_vals *vals, t_fractal *fractal);
double		ft_atodec(char *str);
void		events_init(t_fractal *fractal);
int			manage_key(int key, t_fractal *fractal);
int			manage_some(int key, t_fractal *fractal);
int			manage_more(int key, t_fractal *fractal);
int			manage_exit(t_fractal *fractal);
int			manage_mouse(int button, int x, int y, t_fractal *fractal);
int			manage_track(int x, int y, t_fractal *fractal);
int			get_colour(t_complex z, int i, t_fractal *fractal);
t_colour	smooth_log(t_complex z, int i, t_fractal *fractal);
t_colour	colour_render(int i, t_palette *palette, t_fractal *fractal);
t_colour	blend(t_colour base_c, t_colour next_c, double inter_val);
void		palette_def(t_palette *palette, t_fractal *fractal);
int			lin_interpol(int start_val, int end_val, double point);
t_colour	ft_itoc(int hex);
void		absolute_def(double x, double y, t_vals *vals, t_fractal *fractal);

#endif