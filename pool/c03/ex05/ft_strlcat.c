/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 20:00:21 by amarzoug          #+#    #+#             */
/*   Updated: 2021/07/04 21:11:39 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size && *dest)
	{
		dest++;
		i++;
	}
	if (i == size)
		return (i + ft_len(src));
	j = 0;
	while (src[j])
	{
		if (j < size - i - 1)
			*dest ++ = src[j];
		j++;
	}
	*dest = 0;
	return (i + j);
}
