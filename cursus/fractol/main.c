/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:40:52 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/28 00:37:37 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixal(t_img *img, int x, int y, int color)
{
	char	*ptr;

	ptr = img->addr + (y * img->line_length + x * (img->bit_per_pixel / 8));
	*(unsigned int *)ptr = color;
}

void	fractol_loop(t_data *fractol)
{
	size_t	x;
	size_t	y;

	fractol->scale.re = (fractol->c_max.re - fractol->c_min.re) / WIDTH;
	fractol->scale.im = (fractol->c_max.im - fractol->c_min.im) / HIGHT;
	y = 0;
	while (y < HIGHT)
	{
		fractol->c.im = fractol->c_max.im - y * fractol->scale.re;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->c_min.re + x * fractol->scale.re;
			fractol->fractal_func(fractol);
			ft_put_pixal(&fractol->mlx->mlx_img, x, y, get_color(fractol));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx->mlx_ptr, fractol->mlx->mlx_win,
		fractol->mlx->mlx_img.img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_data	*fractol;

	fractol = ft_initialise(argc, argv);
	if (!fractol)
		return (-1);
	ft_mlx(fractol);
	fractol_loop(fractol);
	mlx_loop(fractol->mlx->mlx_ptr);
}
