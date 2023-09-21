/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <amarzoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:43:17 by amarzoug          #+#    #+#             */
/*   Updated: 2022/06/20 17:43:21 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_struct **a, int yes)
{
	t_struct	*tmp;
	t_struct	*tmp_2;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a);
	tmp_2 = tmp;
	while (tmp_2->next != NULL)
		tmp_2 = tmp_2->next;
	tmp_2->next = tmp;
	*a = (*a)->next;
	tmp->next = NULL;
	if (yes)
		write(1, "ra\n", 3);
}

void	rb(t_struct **b, int yes)
{
	t_struct	*tmp;
	t_struct	*tmp_2;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b);
	tmp_2 = tmp;
	while (tmp_2->next)
		tmp_2 = tmp_2->next;
	tmp_2->next = tmp;
	*b = (*b)->next;
	tmp->next = NULL;
	if (yes)
		write(1, "rb\n", 3);
}

void	rr(t_struct **a, t_struct **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
