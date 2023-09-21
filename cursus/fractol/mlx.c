/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:12:26 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/28 00:38:27 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_hook(int key, t_data *fractol)
{
	if (key == KEY_ESC)
		ft_exit(fractol);
	else if ((key == ARROW_UP || key == ARROW_DOWN)
		|| (key == ARROW_RIGHT || key == ARROW_LEFT))
		ft_move(key, fractol);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		ft_iter(key, fractol);
	else if (key == KEY_C)
		ft_color_shift(fractol);
	else if (key == KEY_H)
		ft_help_win();
	fractol_loop(fractol);
	return (0);
}

int	ft_zoom(int key, int x, int y, t_data *fractol)
{
	t_complex	pos;
	double		zoom;

	if (key == MOUSE_UP || key == MOUSE_DOWN)
	{
		pos.re = fractol->c_min.re + x * fractol->scale.re;
		pos.im = fractol->c_max.im - y * fractol->scale.im;
		if (key == MOUSE_UP)
			zoom = 1.2;
		else
			zoom = 0.8;
		fractol->c_min.re = pos.re + (fractol->c_min.re - pos.re) * zoom;
		fractol->c_max.re = pos.re + (fractol->c_max.re - pos.re) * zoom;
		fractol->c_min.im = pos.im + (fractol->c_min.im - pos.im) * zoom;
		fractol->c_max.im = pos.im + (fractol->c_max.im - pos.im) * zoom;
		fractol_loop(fractol);
	}
	return (0);
}

void	ft_mlx(t_data *fractol)
{
	t_mlx	*mlx;

	fractol->mlx = malloc(sizeof(t_mlx));
	if (!fractol->mlx)
		ft_exit(fractol);
	mlx = fractol->mlx;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_exit(fractol);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WIDTH, HIGHT, "fract-ol");
	if (!mlx->mlx_win)
		ft_exit(fractol);
	mlx->mlx_img.img = mlx_new_image(mlx->mlx_ptr, WIDTH, HIGHT);
	if (!mlx->mlx_img.img)
		ft_exit(fractol);
	mlx->mlx_img.addr = mlx_get_data_addr(mlx->mlx_img.img,
			&mlx->mlx_img.bit_per_pixel, &mlx->mlx_img.line_length,
			&mlx->mlx_img.endian);
	if (!mlx->mlx_img.addr)
		ft_exit(fractol);
	mlx_hook(mlx->mlx_win, 2, 0, ft_key_hook, fractol);
	mlx_hook(mlx->mlx_win, 4, 0, ft_zoom, fractol);
	mlx_hook(mlx->mlx_win, 17, 0, ft_exit, fractol);
}
