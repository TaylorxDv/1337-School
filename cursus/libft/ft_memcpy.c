/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:17:05 by amarzoug          #+#    #+#             */
/*   Updated: 2021/11/09 10:30:29 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*csrc;
	char	*cdes;
	size_t	i;

	csrc = (char *)src;
	cdes = (char *)dst;
	i = 0;
	if (n == '\0' && src == 0)
		return (csrc);
	if (dst == 0 && src == 0)
		return (dst);
	while (i < n)
	{
		cdes[i] = csrc[i];
		i++;
	}
	return (dst);
}
