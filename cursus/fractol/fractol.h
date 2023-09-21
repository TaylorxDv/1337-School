/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:41:25 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/28 00:47:20 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define WIDTH 1080
# define HIGHT 1980

# define ARROW_LEFT		        123
# define ARROW_RIGHT	        124
# define ARROW_UP		        126
# define ARROW_DOWN		        125

# define MOUSE_KEY_RIGHT        2
# define MOUSE_KEY_LEFT         1
# define MOUSE_UP		        4
# define MOUSE_DOWN		        5

# define KEY_ESC		        53
# define KEY_C                  8
# define KEY_H                  4
# define KEY_PLUS		        69
# define KEY_MINUS		        78

typedef struct s_complex	t_complex;
typedef struct s_mlximg		t_mlximg;
typedef struct s_mlx		t_mlx;
typedef struct s_data		t_data;
typedef void				(*t_func_ptr)(t_data *fractol);

typedef struct s_img {
	void	*img;
	void	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	mlx_img;
}			t_mlx;

typedef struct s_mlx_h {
	void	*mlx_ptr_h;
	void	*mlx_win_h;
}			t_mlx_h;

typedef struct s_complex {
	double	re;
	double	im;
}			t_complex;

typedef struct s_data {
	t_mlx		*mlx;
	t_complex	c;
	t_complex	k;
	t_complex	c_max;
	t_complex	c_min;
	t_complex	scale;
	size_t		iter;
	size_t		max_iter;
	t_func_ptr	fractal_func;
	uint8_t		color_shift;
	int			*color_scheme;
}				t_data;

int		get_color(t_data *fractol);
void	ft_color_shift(t_data *fractol);
void	ft_set_color(t_data *fractol);

int		ft_exit(t_data *fractol);
void	ft_complex(t_complex *complex, double re, double im);
void	ft_default(t_data *fractol);
int		ft_atoi(const char *str);

size_t	ft_strlen(const char *str);
double	ft_nat(const char *str);
double	ft_dec(const char *str);

int		ft_strcmp(char *s1, char *s2);
double	ft_atod(const char *str);
void	julia(t_data *fractol);
void	mandelbroat(t_data *fractol);

void	burning_ship(t_data *fractol);
void	print_julia(void);
void	print_arg(void);

void	ft_inputs(int argc, char *argv[], t_data *fractol);
t_data	*ft_initialise(int argc, char *argv[]);
void	ft_move(int key, t_data *fractol);

void	ft_iter(int key, t_data *fractol);
void	ft_help_win(void);
void	ft_put_pixal(t_img *img, int x, int y, int color);

void	fractol_loop(t_data *fractol);
int		ft_key_hook(int key, t_data *fractol);
int		ft_zoom(int key, int x, int y, t_data *fractol);
void	ft_mlx(t_data *fractol);

#endif