/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caperale <caperale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:59:02 by caperale          #+#    #+#             */
/*   Updated: 2026/06/08 12:59:04 by caperale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

bool	ft_above_median(t_node *node)
{
	t_node	*aux;
	int		push_cost_up;
	int		push_cost_down;

	aux = node;
	push_cost_down = 0;
	push_cost_up = 0;
	while (aux)
	{
		aux = aux->prev;
		push_cost_up += 1;
	}
	aux = node;
	while (aux)
	{
		aux = aux->next;
		push_cost_down += 1;
	}
	push_cost_down += 1;
	if (push_cost_down < push_cost_up)
		return (false);
	return (true);
}

void	ft_arrange(t_node ***a, t_node ***b, t_benchmark **count)
{
	t_node	*target;
	int		max_idx;

	while (**b)
	{
		target = find_max(**b);
		max_idx = target->index;
		if ((**b)->index == max_idx)
		{
			pa(a, b, 0, count);
			if ((**a)->next && (**a)->index > (**a)->next->index)
				sa(a, 0, count);
		}
		else if ((**b)->index == max_idx - 1)
		{
			pa(a, b, 0, count);
		}
		else
		{
			if (ft_above_median(target) == true)
				rb(b, 0, count);
			else
				rrb(b, 0, count);
		}
	}
}

void	ft_k_operations(t_node ***a, t_node ***b,
	t_benchmark **count, int *push)
{
	pb(b, a, 0, count);
	rb(b, 0, count);
	++(*push);
}

void	ft_ksort(t_node **a, t_node **b, int n, t_benchmark *count)
{
	int	k;
	int	push;

	if (!a || !*a)
		return ;
	k = (ft_sqrt(ft_stacksize(*a)) * 1.4);
	push = 0;
	while (*a)
	{
		if ((*a)->index <= push)
			ft_k_operations(&a, &b, &count, &push);
		else if ((*a)->index <= push + k)
		{
			pb(&b, &a, 0, &count);
			++push;
		}
		else
			ra(&a, 0, &count);
	}
	ft_arrange(&a, &b, &count);
	if (*a && (*a)->bench)
		ft_bench(n, count);
	free(count);
}
