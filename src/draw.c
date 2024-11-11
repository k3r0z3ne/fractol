/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:12:23 by arotondo          #+#    #+#             */
/*   Updated: 2024/11/11 20:25:20 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	make_draw(t_fractal *fractal, t_meta *data)
{
	// printf("fractal->data : %p\n", fractal->data);
	// printf("data : %p\n", data);
	fractal->pos_x = 0;
	while (fractal->pos_x < data->width)
	{
		fractal->pos_y = 0;
		while (fractal->pos_y < data->height)
		{
			ft_fractal(data, fractal);
			fractal->pos_y++;
		}
		fractal->pos_x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
