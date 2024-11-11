/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:42:28 by arotondo          #+#    #+#             */
/*   Updated: 2024/11/11 19:19:06 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void fractal_choice(t_meta data, t_fractal *fractal)
{
	if (ft_strncmp(data.argv[1], "mandelbrot", 11) == 0)
	{
		fractal->cx = fractal->zx;
		fractal->cy = fractal->zy;
	}
	else if (ft_strncmp(data.argv[1], "julia", 6) == 0)
	{
		fractal->cx = fractal->julia_x;
		fractal->cy = fractal->julia_y;
	}
}

// z.x et z.y sont les coordonnees de la valeur reelle 'z'
// c.x et c.y sont les coordonnees de la valeur imaginaire 'c'

void ft_fractal(t_meta *data, t_fractal *fractal)
{
	int i;

	fractal->zx = (scale_off(fractal->pos_x, -2.0, 2.0, SIZE) * fractal->zoom) + fractal->offset_x;
	fractal->zy = (scale_off(fractal->pos_y, 2.0, -2.0, SIZE) * fractal->zoom) + fractal->offset_y;
	fractal_choice(*data, fractal);
	i = -1;
	while (++i < fractal->iter_max)
	{
		sqrt_complex(fractal, fractal->zx, fractal->zy);
		add_complex(fractal);
		if ((fractal->zx * fractal->zx + fractal->zy * fractal->zy) > 4)
		{
			fractal->color = scale_off(i, 0x000000, 0xFFFFFF, fractal->iter_max);
			my_pixel_put(data, fractal->pos_x, fractal->pos_y, fractal->color);
			break;
		}
	}
	if (i == fractal->iter_max)
		my_pixel_put(data, fractal->pos_x, fractal->pos_y, 0x00000);
	else
		my_pixel_put(data, fractal->pos_x, fractal->pos_y, COLOR * i);
}

// void calculate_burning_ship(t_fractal *fractal)
// {
// 	int i;
// 	double x_temp;

// 	fractal->name = "ship";
// 	i = 0;
// 	fractal->zx = 0.0;
// 	fractal->zy = 0.0;
// 	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
// 	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
// 	while (++i < fractal->max_iterations)
// 	{
// 		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
// 		fractal->zy = fabs(2.0 * fractal->zx * fractal->zy) + fractal->cy;
// 		fractal->zx = fabs(x_temp);
// 		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= __DBL_MAX__)
// 			break;
// 	}
// 	if (i == fractal->max_iterations)
// 		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
// 	else
// 		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * i));
// }