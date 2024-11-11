/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:18:39 by arotondo          #+#    #+#             */
/*   Updated: 2024/11/11 20:26:12 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_meta		data;
	t_fractal	fractal;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0) || \
	(argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0))
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0)
		{
			fractal.julia_x = ft_atodbl(argv[2]);
			fractal.julia_y = ft_atodbl(argv[3]);
		}
		init_data(&data, argv);
		init_fractal(&fractal, &data);
		make_draw(&fractal, &data);
		manage_events(&data, &fractal);
		mlx_loop(data.mlx_ptr);
	}
	else
	{
		ft_printf("commands available :\n> ./fractol mandelbrot\n> \
./fractol julia value1 value2\n");
		exit(1);
	}
	return (0);
}
