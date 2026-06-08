/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caperale <caperale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:12:21 by caperale          #+#    #+#             */
/*   Updated: 2026/06/08 08:27:56 by caperale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_cost_of_push_on_first(t_node *a, int chunk_ranges, int *hold_first)
{
	t_node	*current;

	current = a;
	while (current)
	{
		if (current->index <= chunk_ranges)
		{
			*hold_first = current->index;
			return (ft_cost_to_top(current));
		}
		current = current->next;
	}
	return (-1);
}

int	ft_cost_of_push_on_second(t_node *a, int chunk_ranges, int *hold_second)
{
	t_node	*current;

	current = ft_lstlast(a);
	while (current)
	{
		if (current->index <= chunk_ranges)
		{
			*hold_second = current->index;
			return (ft_cost_to_top(current));
		}
		current = current->prev;
	}
	return (-1);
}

void	ft_move_second_to_top(t_node ***a, int hold_second, t_benchmark **count)
{
	t_node	*current;

	current = ft_lstlast(**a);
	while (current)
	{
		if (current->index == hold_second)
		{
			ft_move_node_to_top(a, current, false, count);
			return ;
		}
		current = current->prev;
	}
}

void	ft_move_first_to_top(t_node ***a, int hold_first, t_benchmark **count)
{
	t_node	*current;

	current = **a;
	while (current)
	{
		if (current->index == hold_first)
		{
			ft_move_node_to_top(a, current, true, count);
			return ;
		}
		current = current->next;
	}
}
