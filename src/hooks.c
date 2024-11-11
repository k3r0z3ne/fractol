/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:22:51 by arotondo          #+#    #+#             */
/*   Updated: 2024/11/11 20:34:25 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	manage_events(t_meta *data, t_fractal *fractal)
{
	mlx_mouse_hook(data->win_ptr, mouse_handler, fractal);
	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &fractal->pos_x, &fractal->pos_y);
	mlx_key_hook(data->win_ptr, hook_handler, fractal);
	mlx_key_hook(data->win_ptr, close_window, data);
	mlx_hook(data->win_ptr, 17, 0, destroy_all, data);
}

int	close_window(int key, t_meta *data)
{
	if (key == 65307)
		destroy_all(data);
	return (0);
}

int	julia_handler(int pos_x, int pos_y, t_fractal *fractal)
{
	if (ft_strncmp(fractal->data->argv[1], "julia", 6) == 0)
	{
		fractal->julia_x = (scale_off(pos_x, -2, 2, SIZE) * fractal->zoom) + fractal->offset_x;
		fractal->julia_y = (scale_off(pos_y, 2, -2, SIZE) * fractal->zoom) + fractal->offset_y;
		make_draw(fractal, fractal->data);
	}
	return 0;
}

int	hook_handler(int key, t_fractal *fractal)
{
	printf("key = %d\n", key);
	if (key == 65361)
	{
		printf("here\n");
		fractal->offset_x -= (0.5 * fractal->zoom);
	}
	if (key == 65363)
		fractal->offset_x += (0.5 * fractal->zoom);
	if (key == 65364)
		fractal->offset_y += (0.5 * fractal->zoom);
	if (key == 65362)
		fractal->offset_y -= (0.5 * fractal->zoom);
	if (key == 'P')
		fractal->iter_max += 10;
	if (key == 'M')
		fractal->iter_max -= 10;
	make_draw(fractal, fractal->data);
	return (0);
}

int	mouse_handler(int key, t_fractal *fractal)
{
	if (key == 5)
		fractal->zoom *= 0.95;
	if (key == 4)
		fractal->zoom *= 1.05;
	else
		return (1);
	make_draw(fractal, fractal->data);
	return (0);
}
