/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:35:03 by amarzoug          #+#    #+#             */
/*   Updated: 2021/11/16 16:55:43 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		i;
	int		n;
	char	*pt;

	i = 0;
	j = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	pt = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) * sizeof(char) + 1);
	if (!pt)
		return (NULL);
	while (s1[i] != '\0')
		pt[n++] = s1[i++];
	while (s2[j] != '\0')
		pt[n++] = s2[j++];
	pt[n] = '\0';
	return (pt);
}
