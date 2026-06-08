/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caperale <caperale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 03:31:17 by caperale          #+#    #+#             */
/*   Updated: 2026/06/08 08:20:03 by caperale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_put_indexes(t_node **stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	if (!stack || !*stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		index = 0;
		compare = *stack;
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

t_node	*ft_find_from_chunk(t_node **stack, int chunk_range)
{
	t_node	*current;

	current = *stack;
	while (current)
	{
		if (current->index <= chunk_range)
			return (current);
		current = current->next;
	}
	return (NULL);
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
	j++;
	if (j < i)
		return (j);
	return (i);
}

int	ft_chunk_sort_loop(t_node ***a, t_node ***b, t_benchmark **count)
{
	t_chunk	chunk;
	int		stack_len;

	stack_len = ft_stacksize(**a);
	chunk.chunk_size = ft_sqrt(stack_len);
	if (chunk.chunk_size == 0)
		return (1);
	chunk.a = a;
	chunk.b = b;
	chunk.count = count;
	chunk.chunk_range = chunk.chunk_size;
	while (**a)
		ft_process_chunk(&chunk);
	return (0);
}

void	ft_chunk_sort(t_node **a, t_node **b, int n, t_benchmark *count)
{
	int	ret;

	ft_put_indexes(a);
	ret = ft_chunk_sort_loop(&a, &b, &count);
	if (ret)
	{
		ft_simple_sort(a, b, n, count);
		return ;
	}
	ft_arrange(&a, &b, &count);
	if (*a && (*a)->bench)
		ft_bench(n, count);
	ft_free_all(a, b);
	free(count);
}
