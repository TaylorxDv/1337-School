/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:34:17 by amarzoug          #+#    #+#             */
/*   Updated: 2021/11/19 16:09:15 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	get_f(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (set[j] == s1[i])
		{	
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

int	get_l(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	if (get_f(s1, set) > i)
		return (i);
	while (set[j])
	{
		if (set[j] == s1[i])
		{
			i--;
			j = -1;
		}
		j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*pt;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = get_l(s1, set) - get_f(s1, set) + 2;
	pt = (char *)malloc(sizeof(char) * len);
	if (!pt)
		return (NULL);
	ft_strlcpy(pt, s1 + get_f(s1, set), len);
	return (pt);
}
