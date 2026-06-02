/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:12:21 by caperale          #+#    #+#             */
/*   Updated: 2026/06/02 21:17:43 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_cost_of_push_on_first(t_node *a, int chunk_ranges, int *hold_first)
{
	t_node	*current;
	int		cost_first;

	cost_first = -1;
	current = a;
	while (current)
	{
		if (current->index <= chunk_ranges)
		{
			hold_first = &current->index;
			cost_first = ft_cost_to_top(current);
		}
		current = current->next;
	}
	return (cost_first);
}

int	ft_cost_of_push_on_second(t_node *a, int chunk_ranges, int *hold_second)
{
	t_node	*current;
	int		cost_second;

	cost_second = -1;
	current = ft_lstlast(a);
	while (current)
	{
		if (current->index <= chunk_ranges)
		{
			hold_second = &current->index;
			cost_second = ft_cost_to_top(current);
		}
		current = current->prev;
	}
	return (cost_second);
}

void	ft_move_second_to_top(t_node *a, t_node *b,
	int hold_second, t_benchmark *count)
{
	t_node	*current;

	current = ft_lstlast(a);
	while (current)
	{
		if (current->index == hold_second)
			ft_move_node_to_top(current, false, count);
		current = current->prev;
	}
	pb(&b, &a, 1, count);
}

void	ft_move_first_to_top(t_node *a, t_node *b, int hold_first,
	t_benchmark *count)
{
	t_node	*current;

	current = a;
	while (current)
	{
		if (current->index == hold_first)
			ft_move_node_to_top(current, true, count);
		current = current->next;
	}
	pb(&b, &a, 1, count);
}
