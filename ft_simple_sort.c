/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:21:35 by caperale          #+#    #+#             */
/*   Updated: 2026/05/28 10:19:06 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lowest_on_a(t_stack_node	*a, t_stack_node	*b, t_benchmark *count)
{
	t_stack_node	*tmp;
	t_stack_node	*bs;

	while (a->next)
	{
		a->has_been_lowest = FALSE;
		tmp = a->next;
		bs = tmp;
		while (bs)
		{
			if (a->nbr < bs->nbr)
			{
				a->next = bs->next;
				sa(&a, 1, count);
				pb(&b, &a, 1, count);
				bs = a->next->prev;
			}
			else
				ra(&a, 1, count);
			bs = bs->next;
		}
		a = tmp->next;
	}
	a->has_been_lowest = TRUE;
	pb(&b, &a, 1);
}

void	ft_lowest_on_b(t_stack_node *a, t_stack_node *b, t_benchmark *count)
{
	rb(&b, 1, count);
	while (b->next && b->index == FALSE)
	{
		pa(&a, &b, 1, count);
		b = b->next;
	}
}

void	ft_simple_sort(t_stack_node *a, t_stack_node *b, t_benchmark *count)
{
	while (a->next)
	{
		ft_lowest_on_a(a, b, count);
		ft_lowest_on_b(a, b, count);
		a = a->next;
	}
}
