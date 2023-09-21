/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:27:02 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/28 00:27:20 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(int key, t_data *fractol)
{
	t_complex	c_size;

	c_size.re = fractol->c_max.re - fractol->c_min.re;
	c_size.im = fractol->c_max.im - fractol->c_min.im;
	if (key == ARROW_UP)
	{
		fractol->c_min.im -= c_size.im * 0.1;
		fractol->c_max.im -= c_size.im * 0.1;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->c_min.im += c_size.im * 0.1;
		fractol->c_max.im += c_size.im * 0.1;
	}
	else if (key == ARROW_LEFT)
	{
		fractol->c_min.re += c_size.re * 0.1;
		fractol->c_max.re += c_size.re * 0.1;
	}
	else if (key == ARROW_RIGHT)
	{
		fractol->c_min.re -= c_size.re * 0.1;
		fractol->c_max.re -= c_size.re * 0.1;
	}
}

void	ft_iter(int key, t_data *fractol)
{
	if (key == KEY_PLUS)
	{
		if (fractol->max_iter == 10000)
			return ;
		else if (fractol->max_iter < 100)
			fractol->max_iter += 1;
		else if (fractol->max_iter < 10000)
		{
			fractol->max_iter = (int)(fractol->max_iter * 1.05);
			if (fractol->max_iter > 10000)
				fractol->max_iter = 10000;
		}
	}
	else if (key == KEY_MINUS)
	{
		if (fractol->max_iter > 100)
			fractol->max_iter = fractol->max_iter * 0.95;
		else if (fractol->max_iter > 1)
			fractol->max_iter -= 1;
	}
	ft_set_color(fractol);
}
