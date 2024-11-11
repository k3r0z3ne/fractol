/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:40:02 by arotondo          #+#    #+#             */
/*   Updated: 2024/11/11 17:25:59 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atodbl(const char *str)
{
	long	int_part;
	double	fract_part;
	double	power;
	int		sign;

	int_part = 0;
	fract_part = 0;
	sign = 1;
	power = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str && *str != '.')
		int_part = (int_part * 10) + (*str++ - 48);
	if (*str == '.')
		++str;
	while (*str)
	{
		power /= 10;
		fract_part = fract_part + (*str++ - 48) * power;
	}
	return ((int_part + fract_part) * sign);
}
