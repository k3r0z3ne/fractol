/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:11:51 by arotondo          #+#    #+#             */
/*   Updated: 2024/11/11 19:18:44 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	add_complex(t_fractal *fractal)
{
	fractal->zx += fractal->cx;
	fractal->zy += fractal->cy;
}

void	sqrt_complex(t_fractal *fractal, double zx, double zy)
{
	fractal->zx = (zx * zx) - (zy * zy);
	fractal->zy = 2.0 * zx * zy;
}

void	my_pixel_put(t_meta *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x <= data->width) && (y >= 0 && y <= data->height))
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

double	scale_off(double pos, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * pos / old_max + new_min);
}
