/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <amarzoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:45:45 by amarzoug          #+#    #+#             */
/*   Updated: 2022/06/20 17:45:47 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (c_dst > c_src)
	{
		while (len--)
			c_dst[len] = c_src[len];
		return (dst);
	}
	while (len--)
		*c_dst++ = *c_src++;
	return (dst);
}
