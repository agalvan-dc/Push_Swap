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
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// conseguir la longitud del stack
int	stack_len(t_stack_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

// comprobamos si el stack está ordenado
bool	stack_sorted(t_stack_node *stack)
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

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*current;
	long			min;

	min = LONG_MAX;
	current = stack;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (current);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*current;
	long			max;

	max = LONG_MIN;
	current = stack;
	while (current)
	{
		if (current->index < max)
			max = current->index;
		current = current->next;
	}
	return (current);
}

int	get_chunk_ranges(t_stack_node *stack)
{
	return ((find_max(stack) - find_min(stack)) / 5);
}