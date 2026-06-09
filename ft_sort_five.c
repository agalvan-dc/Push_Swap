/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:45:44 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/09 16:04:14 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	get_node_pos(t_node *stack, t_node *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}
static void	ft_three_nodes(t_node ***a, t_benchmark **count)
{
	int	first;
	int	second;
	int	third;

	first = (**a)->nbr;
	second = (**a)->next->nbr;
	third = (**a)->next->next->nbr;
	if (first > second && second < third && first < third)
		sa(a, 0, count);
	else if (first > second && second > third)
	{
		sa(a, 0, count);
		rra(a, 0, count);
	}
	else if (first > second && second < third && first > third)
		ra(a, 0, count);
	else if (first < second && second > third && first < third)
	{
		sa(a, 0, count);
		ra(a, 0, count);
	}
	else if (first < second && second > third && first > third)
		rra(a, 0, count);
}

static void	ft_push_min_to_b(t_node ***a, t_node ***b,
		t_benchmark **count, int size)
{
	t_node	*min_node;
	int		pos;

	min_node = find_min(*a);
	pos = get_node_pos(*a, min_node);

	if (pos <= size / 2)
	{
		while (*a != min_node)
			ra(a, 0, count);
	}
	else
	{
		while (*a != min_node)
			rra(a, 0, count);
	}
	pb(a, b, 0, count);
}

void	ft_sort_five(t_node **a, t_node **b, int n, t_benchmark *count)
{
	ft_push_min_to_b(&a, &b, &count, 5);
	ft_push_min_to_b(&a, &b, &count, 4);
	ft_three_nodes(&a, &count);
	pa(&a, &b, 0, &count);
	pa(&a, &b, 0, &count);
	if (*a && (*a)->bench)
		ft_bench(n, count);
	free(count);
}