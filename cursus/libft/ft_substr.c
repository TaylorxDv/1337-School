/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:35:37 by amarzoug          #+#    #+#             */
/*   Updated: 2021/11/18 19:16:29 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*dest;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		dest = ft_calloc(1, 1);
		return (dest);
	}
	if (ft_strlen((char *)(s + start)) < len)
		len = ft_strlen((char *)(s + start));
	dest = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!dest)
		return (NULL);
	ft_strncpy(dest, (s + start), len);
	return (dest);
}
