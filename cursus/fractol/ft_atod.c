/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:22:18 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/28 00:29:48 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(const char *str)
{
	int	res ;
	int	i ;

	res = 0 ;
	i = 0 ;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

double	ft_nat(const char *str)
{
	double	nat;
	char	c_nat[5];
	int		i;

	i = 0;
	while (str[i] && str[i] != '.')
	{
		c_nat[i] = str[i];
		i++;
	}
	c_nat[i] = '\0';
	nat = ft_atoi(c_nat) + 0.0;
	return (nat);
}

double	ft_dec(const char *str)
{
	double	dec;
	char	c_dec[8];
	int		sign;
	int		i;
	int		j;

	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	while (str[i] != '.')
		i++;
	i++;
	j = 0;
	while (str[i])
		c_dec[j++] = str[i++];
	c_dec[j] = '\0';
	dec = (ft_atoi(c_dec) + 0.0) / pow(10, ft_strlen(c_dec)) * sign;
	return (dec);
}

double	ft_atod(const char *str)
{	
	return ((double)(ft_nat(str) + ft_dec(str)));
}
