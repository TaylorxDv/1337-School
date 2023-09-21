/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:08:06 by amarzoug          #+#    #+#             */
/*   Updated: 2021/07/13 09:10:28 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		len;
	int		i;

	len = 0;
	while (src[len] != '\0')
		len++;
	ptr = (char *) malloc((len * sizeof(char)) + 1);
	if(ptr == NULL)
		return NULL;
	i = 0;
	while (src[i] != '\0')
	{	
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
