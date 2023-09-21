/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:03:24 by amarzoug          #+#    #+#             */
/*   Updated: 2021/06/30 18:00:09 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	upper_lower_numbers(char c)
{
	return (lowercase(c) || uppercase(c) || (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{	
	int	i;

	i = 0;
	if (lowercase(str[0]))
		str[0] = str[0] - 32;
	while (str[i++] != '\0')
	{
		if (! upper_lower_numbers(str[i]) && lowercase(str[i + 1]))
			str[i + 1] = str[i + 1] - 32;
		else if (! upper_lower_numbers(str[i]) && lowercase(str[i + 1]))
			str[i + 1] = str[i + 1] + 32;
	}
	return (str);
}
