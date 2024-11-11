/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:13:22 by arotondo          #+#    #+#             */
/*   Updated: 2024/11/11 20:32:24 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define COLOR 0xFCBE11
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define RED 0xFF0000
# define SIZE 1080

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_fractal
{
	int		pos_x;
	int		pos_y;
	int		iter_max;
	int		color;
	double	zoom;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	julia_x;
	double	julia_y;
	struct s_meta *data;
}			t_fractal;

typedef struct s_meta
{
	char	**argv;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		line_length;
	int		endian;
}			t_meta;

/* main */
int		main(int argc, char **argv);

/* init */
void	init_data(t_meta *data, char **argv);
void	init_fractal(t_fractal *fractal, t_meta *data);

/* draw */
void	make_draw(t_fractal *fractal, t_meta *data);

/* fractals */
void	fractal_choice(t_meta data, t_fractal *fractal);
void	ft_fractal(t_meta *data, t_fractal *fractal);
void	ft_julia(t_meta *data, t_fractal *fractal);

/* error */
int		destroy_all(t_meta *data);

/* utils */
void	add_complex(t_fractal *fractal);
void	sqrt_complex(t_fractal *fractal, double zx, double zy);
void	my_pixel_put(t_meta *data, int x, int y, int color);
double	scale_off(double pos, double new_min, double new_max, double old_max);

/* hooks */
void	manage_events(t_meta *data, t_fractal *fractal);
int		close_window(int key, t_meta *data);
int		julia_handler(int pos_x, int pos_y, t_fractal *fractal);
int		hook_handler(int key, t_fractal *fractal);
int		mouse_handler(int key, t_fractal *fractal);

#endif