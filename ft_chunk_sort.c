/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 03:31:17 by caperale          #+#    #+#             */
/*   Updated: 2026/06/02 20:21:59 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_put_indexes(t_node *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->nbr < current->nbr)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

t_node	*ft_find_from_chunk(t_node *stack, int chunk_range)
{
	t_node	*current;

	current = stack;
	while (current)
	{
		if (current->nbr <= chunk_range)
			return (current);
		current = current->next;
	}
	return (current);
}

int	ft_cost_to_top(t_node *a)
{
	t_node	*node;
	int		i;
	int		j;

	j = 0;
	i = 0;
	node = a;
	while (node)
	{
		node = node->prev;
		i++;
	}
	node = a;
	while (node)
	{
		node = node->next;
		j++;
	}
	//j++; esto por que?
	if (j < i)
		return (j);
	return (i);
}

int	ft_chunk_sort_loop(t_node *a, t_node *b, t_benchmark *count)
{
	int		chunk_ranges;
	int		hold_first;
	int		hold_second;
	int		stack_len;
	int		i;

	i = 0;
	stack_len = ft_stacksize(a);
	chunk_ranges = stack_len / 5;
	if (chunk_ranges == 0)
		return (1);
	while (i < stack_len + 5 - 1)
	{
		if ((ft_cost_of_push_on_first(a, chunk_ranges, &hold_first)
				<= ft_cost_of_push_on_second(a, chunk_ranges, &hold_second))
			&& ft_cost_of_push_on_first(a, chunk_ranges, &hold_first) != -1)
			ft_move_first_to_top(a, b, hold_first, count);
		else if (ft_cost_of_push_on_first(a, chunk_ranges, &hold_first)
			> ft_cost_of_push_on_second(a, chunk_ranges, &hold_second))
			ft_move_second_to_top(a, b, hold_second, count);
		else if (ft_cost_of_push_on_first(a, chunk_ranges, &hold_first) == -1)
			chunk_ranges += stack_len / 5;
		i++;
	}
	return (0);
}

void	ft_chunk_sort(t_node *a, t_node *b, int n, t_benchmark *count)
{
	ft_put_indexes(a);
	if (ft_chunk_sort_loop(a, b, count))
		ft_simple_sort(a, b, n, count);
	if (a->bench && !ft_chunk_sort_loop(a, b, count))
		ft_bench(n, count);
	ft_arrange(a, b, count);
	ft_free_all(a, b);
}
