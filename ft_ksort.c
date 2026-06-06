/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:50:55 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/06 12:03:58 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

bool	ft_above_median(t_node *a)
{
	t_node			*aux;
	int				push_cost_up;
	int				push_cost_down;

	aux = a;
	push_cost_down = 0;
	push_cost_up = 0;
	while (aux)
	{
		aux = aux->prev;
		push_cost_up += 1;
	}
	while (a)
	{
		a = a->next;
		push_cost_down += 1;
	}
	push_cost_down += 1;
	if (push_cost_down < push_cost_up)
		return (false);
	return (true);
}

void	ft_arrange(t_node ***a, t_node ***b, t_benchmark **count)
{
	t_node	*tmp;
	
	while (*b)
	{
		tmp = find_max(**b);
		ft_move_node_to_top(&tmp, ft_above_median(**b), count);
		pa(a, b, 0, count);
		(**b) = (**b)->next;
	}
}

void	ft_k_operations(t_node ***a, t_node ***b, t_benchmark **count, int *push)
{
	pb(a, b, 0, count);
	rb(b, 0, count);
	++(*push);
}

void	ft_ksort(t_node **a, t_node **b, int n, t_benchmark *count)
{
	int		k;
	int		push;

	k = ft_sqrt(ft_stacksize(*a)) * 4.12;
	push = 0;
	while ((*a)->next)
	{
		if ((*a)->index <= push)
			ft_k_operations(&a, &b, &count, &push);
		else if ((*a)->index <= push + k)
		{
			pb(&a, &b, 0, &count);
			++push;
		}
		else
			ra(&a, 0, &count);
	}
	ft_arrange(&a, &b, &count);
	if ((*a)->bench)
		ft_bench(n, count);
	ft_free_all(a, b);
}
