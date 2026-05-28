/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 03:31:17 by caperale          #+#    #+#             */
/*   Updated: 2026/05/28 10:22:28 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	put_indexes(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*compare;
	int				index;

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

t_stack_node	*find_from_chunk(t_stack_node *stack, int chunk_range)
{
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		if (current->nbr <= chunk_range)
			return (current);
		current = current->next;
	}
	return (current);
}

int	cost_to_top(t_stack_node *a)
{
	t_stack_node	*node;
	int				i;
	int				j;

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
	j++;
	if (j < i)
		return (j);
	return (i);
}

void	ft_chunk_sort(t_stack_node *a, t_stack_node *b, t_benchmark *count)
{
	int	chunk_ranges;
	int	hold_first;
	int	hold_second;

	put_indexes(a);
	chunk_ranges = stack_len(a) / 5;
	if (cost_of_push_on_first(a, chunk_ranges, &hold_first)
		<= cost_of_push_on_second(a, chunk_ranges, &hold_second))
		move_first_to_top(a, hold_first, count);
	else
		move_second_to_top(a, hold_second, count);

}
