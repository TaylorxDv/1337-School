/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibonnaci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:42:07 by amarzoug          #+#    #+#             */
/*   Updated: 2021/07/10 13:54:20 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonnaci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	else
		return (ft_fibonnaci(index - 1) + ft_fibonnaci(index - 2));
}
