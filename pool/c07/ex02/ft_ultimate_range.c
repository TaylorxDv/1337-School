/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:37:23 by amarzoug          #+#    #+#             */
/*   Updated: 2021/07/13 10:33:35 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	ptr = (int *) malloc((ma - min) * sizeof(int));
	if (min >= max)
		ptr = NULL;
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (min < max)
	{
		ptr[i] = min;
		i++;
		min++;
	}
	return (ptr);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (range == NULL)
	{
		return (0);
	}	
	return (max - min);
}
