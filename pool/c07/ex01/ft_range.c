/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:26:13 by amarzoug          #+#    #+#             */
/*   Updated: 2021/07/13 10:29:11 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	ptr = (int *) malloc(max * sizeof(int));
	if (min >= maxi)
		return (0);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		i++;
		min++;
	}
	return (ptr);
}
