/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:22:21 by amarzoug          #+#    #+#             */
/*   Updated: 2021/07/14 18:40:40 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *dest)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	p = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

struct	s_stock_str	*ft_strs_to_tab(int argc, char *argv[])
{
	t_stock_str	*p;
	int			i;

	if (argc < 0)
		argc = 0;
	p = malloc((argc + 1) * sizeof(t_stock_str));
	if (!p)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		p[i].size = ft_strlen(argv[i]);
		p[i].str = argv[i];
		p[i].copy = ft_strdup(argv[i]);
		i++;
	}
	p[i].str = 0;
	return (p);
}
