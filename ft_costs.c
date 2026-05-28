/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:12:21 by caperale          #+#    #+#             */
/*   Updated: 2026/05/28 08:37:08 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	cost_of_push_on_first(t_stack_node *a, int chunk_ranges, int *hold_first)
{
	t_stack_node	*current;
	int				cost_first;

	cost_first = 0;
	current = a;
	while (current)
	{
		if (current->index <= chunk_ranges)
		{
			hold_first = current->index;
			cost_first = cost_to_top(current);
		}
		current = current->next;
	}
	return (cost_first);
}

int	cost_of_push_on_second(t_stack_node *a, int chunk_ranges, int *hold_second)
{
	t_stack_node	*current;
	int				cost_second;

	current = ft_lstlast(a);
	while (current)
	{
		if (current->index <= chunk_ranges)
		{
			hold_second = current->index;
			cost_second = cost_to_top(current);
		}
		current = current->prev;
	}
	return (cost_second);
}

void	move_second_to_top(t_stack_node *a, int hold_second)
{
	t_stack_node	*current;

	current = ft_lstlast(a);
	while (current)
	{
		if (current->index == hold_second)
			ft_move_node_to_top(current, FALSE);
		current = current->prev;
	}
}

void	move_first_to_top(t_stack_node *a, int hold_first)
{
	t_stack_node	*current;

	current = a;
	while (current)
	{
		if (current->index == hold_first)
			ft_move_node_to_top(current, TRUE);
		current = current->next;
	}
}

