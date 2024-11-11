/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:16:27 by arotondo          #+#    #+#             */
/*   Updated: 2024/11/11 20:25:57 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_data(t_meta *data, char **argv)
{
	data->argv = argv;
	data->width = SIZE;
	data->height = SIZE;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height, "fract'ol");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		exit(1);
	}
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	if (!data->img_ptr)
	{
		free(data->mlx_ptr);
		free(data->win_ptr);
		exit(1);
	}
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->line_length, &data->endian);
	if (!data->addr)
		destroy_all(data);
}

void	init_fractal(t_fractal *fractal, t_meta *data)
{
	fractal->data = data;
	fractal->zoom = 1.1;
	fractal->iter_max = 42;
	fractal->offset_x = 0.00;
	fractal->offset_y = 0.00;
}
