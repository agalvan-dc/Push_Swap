/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:33:21 by cperales          #+#    #+#             */
/*   Updated: 2025/05/26 01:33:21 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// encontrar puntero al ultimo bloque del stack
t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// comprobamos si el stack está ordenado
bool	stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->nbr < stack->next->nbr)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

t_node	*find_min(t_node *stack)
{
	t_node	*current;
	t_node	*min_node;
	long	min;

	min = LONG_MAX;
	current = stack;
	min_node = stack;
	while (current)
	{
		if (current->index < min)
		{
			min = current->index;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

t_node	*find_max(t_node *stack)
{
	t_node	*current;
	t_node	*max_node;
	long	max;

	max = LONG_MIN;
	current = stack;
	max_node = stack;
	while (current)
	{
		if (current->index > max)
		{
			max = current->index;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

int	get_chunk_ranges(t_node *stack)
{
	return ((find_max(stack) - find_min(stack)) / 5);
}
