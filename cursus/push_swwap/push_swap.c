/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <amarzoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:36:06 by amarzoug          #+#    #+#             */
/*   Updated: 2022/06/20 17:36:09 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_struct **a)
{
	while (1)
	{
		if ((*a)->nb > (*a)->next->nb && (*a)->nb < (*a)->next->next->nb)
			sa(*a);
		else if ((*a)->nb > (*a)->next->next->nb
			&& (*a)->next->nb > (*a)->next->next->nb)
			ra(a, 1);
		else if ((*a)->nb > (*a)->next->nb
			&& (*a)->next->nb < (*a)->next->next->nb)
			ra(a, 1);
		else if ((*a)->next->nb > (*a)->next->next->nb)
			rra(a, 1);
		if ((*a)->nb < (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb)
			return ;
	}
}

int	ft_is_sorted(t_struct *a)
{
	t_struct	*tmp;

	tmp = a->next;
	while (tmp)
	{
		if (a->nb > tmp->nb)
			return (0);
		a = a->next;
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int			len;
	t_struct	*a;
	t_struct	*b;

	if (ac == 1)
		exit (0);
	a = NULL;
	b = NULL;
	a = ft_initialize(a, ac, av);
	len = ft_lstsize(a);
	if (len == 1)
		return (0);
	else if (len == 3)
		ft_sort_three(&a);
	else
	{
		ft_indexing(a);
		markup_0(a);
		ft_send_to_b(&a, &b);
		ft_send(&a, &b);
		ft_fix(&a);
		ft_lstclear(&a);
		ft_lstclear(&b);
	}
}
