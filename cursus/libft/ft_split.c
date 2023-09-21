/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:06:19 by amarzoug          #+#    #+#             */
/*   Updated: 2021/11/19 15:59:28 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_arr(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (i);
}

static int	all(char *str, char **str0)
{
	if (!str)
	{
		while (str)
			free(str++);
		free(str0);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		index;
	int		len;
	int		arr;

	if (!s)
		return (NULL);
	arr = count_arr(s, c);
	index = 0;
	str = ft_calloc((arr + 1), sizeof(char *));
	if (!str)
		return (NULL);
	while (*s && index < arr)
	{
		while (*s == c && *s)
			s++;
		len = 0;
		while (*s != c && *s && ++len)
			s++;
		str[index] = ft_substr(s - len, 0, len);
		if (all(str[index], str))
			return (NULL);
		index++;
	}
	return (str);
}
