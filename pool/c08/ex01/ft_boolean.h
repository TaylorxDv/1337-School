/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:41:11 by amarzoug          #+#    #+#             */
/*   Updated: 2021/07/14 13:07:59 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>
typedef int		t_bool;
# define EVEN(x) (x % 2 == 0)
# define TRUE 1
# define FALSE 0
# define EVEN_MSG "I have an even  number of arguments \n"
# define ODD_MSG "I have an odd number of arguments \n"
# define SUCCESS 0
#endif
