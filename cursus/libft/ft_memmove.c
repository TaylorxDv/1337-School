/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:40:25 by amarzoug          #+#    #+#             */
/*   Updated: 2021/11/11 16:28:58 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;
	char		*dest1;
	const char	*src1;

	cdst = dst;
	csrc = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (cdst < csrc)
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	else
	{
		dest1 = cdst + (len - 1);
		src1 = csrc + (len - 1);
		while (len--)
			*dest1-- = *src1--;
	}
	return (dst);
}
