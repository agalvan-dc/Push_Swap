/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:50:55 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/02 21:29:54 by agalvan-         ###   ########.fr       */
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
	if (push_cost_down < push_cost_up)
		return (false);
	return (true);
}

void	ft_arrange(t_node *a, t_node *b, t_benchmark *count)
{
	while (b)
	{
		ft_move_node_to_top(find_max(b), ft_above_median(b), count);
		pa(&a, &b, 0, count);
		b = b->next;
	}
}
void	ft_k_operations(t_node **a, t_node **b, t_benchmark *count, int *push)
{
	pb(a, b, 0, count);
	rb(b, 0, count);
	++(*push);
}

void	ft_ksort(t_node *a, t_node *b, int n, t_benchmark *count)
{
	int		k;
	int		size;
	int		push;

	k = ft_sqrt(ft_stacksize(a)) * 4.12;
	ft_put_indexes(a);
	size = ft_stacksize(a);
	push = 0;
	while (push < size)
	{
		if (a->index > ft_stacksize(b) + k)
			ft_k_operations(&a, &b, count, &push);
		else if (a->index > ft_stacksize(b))
		{
			pb(&a, &b, 0, count);
			++push;
		}
		else
			ra(&a, 0, count);
	}
	ft_arrange(a, b, count);
	if (a->bench)
		ft_bench(n, count);
	ft_free_all(a, b);
}
