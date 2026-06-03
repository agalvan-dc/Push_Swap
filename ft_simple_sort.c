/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:21:35 by caperale          #+#    #+#             */
/*   Updated: 2026/06/02 21:35:09 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lowest_on_a(t_node	**a, t_node	**b, t_benchmark *count)
{
	t_node	*tmp;
	t_node	*bs;

	while ((*a)->next)
	{
		(*a)->has_been_lowest = false;
		tmp = (*a)->next;
		bs = tmp;
		while (bs)
		{
			if ((*a)->nbr < bs->nbr)
			{
				(*a)->next = bs->next;
				sa(a, 0, count);
				pb(b, a, 0, count);
				bs = (*a)->next->prev;
			}
			else
				ra(a, 0, count);
			bs = bs->next;
		}
		*a = tmp->next;
	}
	(*a)->has_been_lowest = true;
	pb(b, a, 0, count);
}

void	ft_lowest_on_b(t_node **a, t_node **b, t_benchmark *count)
{
	rb(b, 0, count);
	while ((*b)->next && (*b)->index == false)
	{
		pa(a, b, 0, count);
		b = b->next;
	}
}

void	ft_simple_sort(t_node *a, t_node *b, int n, t_benchmark *count)
{
	while (a->next)
	{
		ft_lowest_on_a(&a, &b, count);
		ft_lowest_on_b(&a, &b, count);
		a = a->next;
	}
	while (b)
		pa(&a, &b, 0, count);
	if (a->bench)
		ft_bench(n, count);
	ft_free_all(a, b);
}
