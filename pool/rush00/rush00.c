/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:47:33 by amarzoug          #+#    #+#             */
/*   Updated: 2021/06/26 11:50:49 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	show(int i, int y, int c)
{
	if (c == 1)
    {
	if (i == 0 || i == y-1)
    {
		putchar('o');
    }
	else
    {
		putchar('|');
    }
    }else{
        if (i == 0 || i == y-1)
            {
				putchar('-');
            }
			else
            {
			putchar(' ');
            }
    }
}

void	rush00(int x, int y)
{
	int	i;
	int	j;
    
	i = 0;  
	while (i < y)
    {
		show(i, y, 1);
		j =  1;
		while (j <= x - 2)
        {
           show(i, y, 0);
			j++;
        }
		if (x != 1)
        {
		show(i, y, 1);
        }
		putchar('\n');
		i++;
    }  
}

int	main()
{
	rush00(5, 3);
	return 0;
}
