/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:23:17 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/28 00:30:55 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_data *fractol)
{
	t_complex	z;
	t_complex	tmp;

	z.re = fractol->c.re;
	z.im = fractol->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im;
	fractol->iter = 0;
	while ((tmp.re + tmp.im <= 4) && fractol->iter < fractol->max_iter)
	{
		z.im = 2 * z.re * z.im + fractol->k.im;
		z.re = tmp.re - tmp.im + fractol->k.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		fractol->iter++;
	}
}

void	mandelbroat(t_data *fractol)
{
	t_complex	z;
	t_complex	tmp;

	z.re = fractol->c.re;
	z.im = fractol->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im;
	fractol->iter = 0;
	while ((tmp.re + tmp.im <= 4) && fractol->iter < fractol->max_iter)
	{
		z.im = 2 * z.re * z.im + fractol->c.im;
		z.re = tmp.re - tmp.im + fractol->c.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		fractol->iter++;
	}
}

void	burning_ship(t_data *fractol)
{
	t_complex	z;
	t_complex	tmp;

	z.re = fractol->c.re;
	z.im = fractol->c.im;
	tmp.re = z.re * z.re;
	tmp.im = z.im * z.im;
	fractol->iter = 0;
	while ((tmp.re + tmp.im <= 4) && fractol->iter < fractol->max_iter)
	{
		z.im = 2 * fabs(z.re * z.im) + fractol->c.im;
		z.re = tmp.re - tmp.im + fractol->c.re;
		tmp.re = z.re * z.re;
		tmp.im = z.im * z.im;
		fractol->iter++;
	}
}
