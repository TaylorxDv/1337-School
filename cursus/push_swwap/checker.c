/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzoug <amarzoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:34:59 by amarzoug          #+#    #+#             */
/*   Updated: 2022/06/20 17:35:51 by amarzoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_line(int fd)
{
	char	line[4];
	int		i;

	i = 0;
	ft_bzero(line, 4);
	while (read(fd, line + (i), 1) > 0)
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}

static bool	apply_operation(char *line, t_struct **a, t_struct **b)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_pa_pb(a, b, NULL);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_pa_pb(b, a, NULL);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_sa_sb(a, NULL);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_sa_sb(b, NULL);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_ss(a, b, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_ra_rb(a, NULL);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_ra_rb(b, NULL);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rr(a, b, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_rra_rrb(a, NULL);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_rra_rrb(b, NULL);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_rrr(a, b, 0);
	else
		return (free_line(0), false);
	return (true);
}

static void	ft_sort(t_struct **a, t_struct **b)
{
	char	*line;
	bool	aplly;

	line = get_line(0);
	while (line)
	{
		aplly = apply_operation(line, a, b);
		free(line);
		if (!aplly)
		{
			stack_clear(a);
			stack_clear(b);
			ft_exit();
		}
		line = get_line(0);
	}
}

bool	ft_is_ok(t_struct *a, t_struct *b)
{
	t_struct	*prev;

	if (b)
		return (false);
	prev = a;
	while (a)
	{
		if (prev->nb > a->nb)
			return (false);
		prev = a;
		a = a->next;
	}
	return (true);
}

int	main(int ac, char *av[])
{
	t_struct	*a;
	t_struct	*b;

	if (ac < 2)
		return (0);
	a = ft_initialize(a, ac, av);
	b = NULL;
	ft_sort(&a, &b);
	if (ft_is_ok(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
