/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:15:51 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/28 00:16:15 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calc_color(t_data *fractol, size_t i);

int	get_color(t_data *fractol)
{
	return (fractol->color_scheme[fractol->iter]);
}

void	ft_color_shift(t_data *fractol)
{
	fractol->color_shift = (fractol->color_shift + 1) % 3;
	ft_set_color(fractol);
}

static int	calc_color(t_data *fractol, size_t i)
{
	uint8_t	cs;
	uint8_t	rgb[3];
	double	div;

	cs = fractol->color_shift;
	div = (double)i / fractol->max_iter;
	if (fractol->color_shift < 3)
	{
		rgb[cs % 3] = 9 * (1 - div) * pow(div, 3) * 255;
		rgb[(cs + 1) % 3] = 16 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * pow((1 - div), 3) * div * 255;
	}
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	ft_set_color(t_data *fractol)
{
	size_t	i;

	i = -1;
	while (++i <= fractol->max_iter)
		fractol->color_scheme[i] = calc_color(fractol, i);
}
