/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:20:28 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/28 00:40:25 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i ;

	i = 0 ;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++ ;
	return (s1[i] - s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i ;

	i = 0 ;
	while (str[i])
		i++;
	return (i);
}

void	print_julia(void)
{
	printf("\033[1;32m");
	printf("                   Julia c values :\n");
	printf("\033[1;33m");
	printf("%*s\n", 25 + 22, "~~~> c = 0.285 + 0.0i");
	printf("%*s\n", 25 + 50, "~~~> c = (φ − 2) + (φ − 1)i = −0.4 + 0.6i");
	printf("%*s\n", 25 + 23, "~~~> c = 0.285 + 0.01i");
	printf("%*s\n", 25 + 24, "~~~> c = 0.45 + 0.1428i");
	printf("%*s\n", 25 + 32, "~~~> c = −0.70176 − 0.3842i");
	printf("%*s\n", 25 + 30, "~~~> c = −0.835 − 0.2321i");
	printf("%*s\n", 25 + 29, "~~~> c = −0.7269 + 0.1889i");
	printf("%*s\n", 25 + 27, "~~~> c = c = 0.0 + −0.8i");
	printf("\033[1;34m");
	printf("\n\n\n");
	printf("Usage ~~~~> ./fractol Julia");
	printf(" [real value of c] [imaginary value of c]\n");
	printf("\n\n\n");
}

void	print_arg(void)
{
	printf("\nwrong argument (check the argument syntax)\n");
	printf("first of all type: -> ./fractol\n");
	printf("for julia type: -> julia\n");
	printf("for mandelbroat type: -> MB\n");
	printf("for burning_ship type: -> BS\n");
	printf("for julia value: -> julia_value\n");
}

void	ft_help_win(void)
{
	void	*ptr;
	void	*win;
	int		c;

	ptr = mlx_init();
	win = mlx_new_window(ptr, 700, 700, "HELP");
	c = 0xFFFFFF;
	mlx_string_put(ptr, win, 320, 100, c, "help");
	mlx_string_put(ptr, win, 220, 200, c, "C   	Change color" );
	mlx_string_put(ptr, win, 220, 220, c, "+    Iterate" );
	mlx_string_put(ptr, win, 220, 240, c, "-    !Iterate" );
	mlx_string_put(ptr, win, 220, 260, c, "Arrow up    UP" );
	mlx_string_put(ptr, win, 220, 280, c, "Arrow down  DOWN" );
	mlx_string_put(ptr, win, 220, 300, c, "Arrow right Right" );
	mlx_string_put(ptr, win, 220, 320, c, "Arrow left  Left" );
	mlx_string_put(ptr, win, 220, 340, c, "Scroll up   Zoom in" );
	mlx_string_put(ptr, win, 220, 360, c, "Scroll down Zoom out" );
	mlx_string_put(ptr, win, 220, 380, c, "Esc            Exit" );
	mlx_loop(ptr);
}
