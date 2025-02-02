/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:00:07 by liovino           #+#    #+#             */
/*   Updated: 2025/02/02 16:48:39 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ERROR_MESS "Problem with request...Please enter \n\t\"./fractol Mandelbrot\" or \n\t\"./fractol Julia <value_x> <value_y>\""

# define WIDTH 600
# define HEIGHT 600
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define R_COLOUR 0x047878 //verdino
# define FORREST_GREEN 0x228B22
# define ROYAL_BLUE 0x4169E1
# define MAGENTA 0xFF00FF

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_complex
{
	double	real_x;
	double	imaginary_y;
}	t_complex;

typedef struct s_image
{
	void	*image_ptr; //pointer to image struct
	char	*pix_ptr; //points to the actual pixel, will use it to change pixels in image
	int		bytes_pp; //how many bytes for pixel (should be 32)
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connect;
	void		*mlx_window;
	t_image		image;
	double		escape_val;
	int			image_def;
	double		julia_x;
	double		julia_y;
}	t_fractal;

//typedef struct	s_colour //forse servirà
//{
//	uint8_t	r;
//	uint8_t	g;
//	uint8_t	b;
//}	t_colour;

//typedef	struct	s_palette
//{
//	t_colour	black;
//	t_colour	white;
//	t_colour	red;
//	t_colour	green;
//	t_colour	blue;
//}	t_palette

void		fractal_init(t_fractal *fractal);
void		malloc_err(void);
double		scaling(double num, double o_min, double o_max, double n_min, double n_max);
t_complex	c_sum(t_complex z, t_complex z_sq);
t_complex	c_square(t_complex z);
void		fractal_render(t_fractal *fractal);
void		manage_pixel(double x, double y, t_fractal *fractal);
void		show_pixel(int x, int y, t_image *img, int colour);
void		def_data(t_fractal *fractal);
void		mandelbrot_def(double x, double y, t_complex *z, t_complex *c);
void		julia_def(double x, double y, t_complex *z, t_complex *c, t_fractal *fractal);
double		ft_atodec(char *str);
//void		choose_fractal(t_fractal *fractal, double x, double y, t_complex z, t_complex c);

#endif