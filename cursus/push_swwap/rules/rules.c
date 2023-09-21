/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <amarzoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:43:30 by amarzoug          #+#    #+#             */
/*   Updated: 2022/06/20 17:43:33 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_struct *a)
{
	int			tmp;
	t_struct	*ptr;

	if (!a || !a->next)
		return ;
	tmp = a->nb;
	ptr = a->next;
	a->nb = ptr->nb;
	ptr->nb = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_struct *b)
{
	int			tmp;
	t_struct	*ptr;

	if (!b || !b->next)
		return ;
	tmp = b->nb;
	ptr = b->next;
	b->nb = ptr->nb;
	ptr->nb = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_struct *a, t_struct*b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_struct **a, t_struct **b)
{
	t_struct	*tmp;

	if (!*b)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_struct **a, t_struct **b)
{
	t_struct	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	write(1, "pb\n", 3);
}
