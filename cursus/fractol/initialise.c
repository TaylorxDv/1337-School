/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:07:14 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/28 00:37:06 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit(t_data *fractol)
{
	if (fractol->mlx)
	{
		mlx_destroy_window(fractol->mlx->mlx_ptr, fractol->mlx->mlx_win);
		mlx_destroy_image(fractol->mlx->mlx_ptr, fractol->mlx->mlx_img.img);
		free(fractol->mlx);
	}
	free(fractol->color_scheme);
	free(fractol);
	exit(0);
}

void	ft_inputs(int argc, char *argv[], t_data *fractol)
{
	if (argc == 1 && !ft_strcmp(argv[0], "./fractol"))
		print_arg();
	else if ((argc == 2 || argc == 4) && !ft_strcmp(argv[1], "julia"))
	{
		if (argc == 3 || argc == 4)
		{
			fractol->k.re = ft_atod(argv[2]);
			fractol->k.im = ft_atod(argv[3]);
		}
		fractol->fractal_func = julia;
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "julia_value"))
		print_julia();
	else if (argc == 2 && !ft_strcmp(argv[1], "MB"))
		fractol->fractal_func = mandelbroat;
	else if (argc == 2 && !ft_strcmp(argv[1], "BS"))
		fractol->fractal_func = burning_ship;
	else
		print_arg();
	if (!fractol->fractal_func)
		ft_exit(fractol);
}

void	ft_complex(t_complex *complex, double re, double im)
{
	complex->re = re;
	complex->im = im;
}

void	ft_default(t_data *fractol)
{
	fractol->max_iter = 100;
	ft_complex(&fractol->c_min, -2, -2);
	fractol->c_max.im = 2;
	fractol->c_max.re = (WIDTH / HIGHT
			* (fractol->c_min.im - fractol->c_max.im)
			+ fractol->c_max.im);
	ft_complex(&fractol->k, -0.8, 0.156);
	ft_set_color(fractol);
}

t_data	*ft_initialise(int argc, char *argv[])
{
	t_data	*fractol;

	fractol = malloc(sizeof(t_data));
	if (!fractol)
		return (NULL);
	fractol->color_scheme = malloc(sizeof(int) * 10000);
	if (!fractol->color_scheme)
		ft_exit(fractol);
	fractol->color_shift = 0;
	fractol->mlx = NULL;
	ft_default(fractol);
	ft_inputs(argc, argv, fractol);
	return (fractol);
}
