/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:54:48 by amarzoug          #+#    #+#             */
/*   Updated: 2021/07/13 10:38:00 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		n;
	char	*pt;

	pt = (char *) malloc(sizeof(strs));
	i = 0;
	n = 0;
	while (i < size)
	{	
		j = 0;
		while (strs[i][j] != '\0')
		{
			pt[n++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
		{	
			pt[n++] = sep[j++];
		}
		i++;
	}
	pt[n] = '\0';
	return (pt);
}
