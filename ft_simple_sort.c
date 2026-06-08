/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:21:35 by caperale          #+#    #+#             */
/*   Updated: 2026/06/08 17:10:18 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lowest_on_b(t_node ***a, t_node ***b, t_benchmark **count)
{
	if (!*b || !**b)
		return ;
	rb(b, 0, count);
	while (**b && (**b)->has_been_lowest != true)
		pa(a, b, 0, count);
}

int	ft_is_sorted(t_node **stack)
{
	t_node	*current;
	int		is_sorted;

	if (!stack || !*stack)
		return (-1);
	current = (*stack);
	is_sorted = 0;
	while (current->next)
	{
		if (current->index > current->next->index)
			is_sorted = 1;
		current = current->next;
	}
	return (is_sorted);
}

void	ft_simple_sort(t_node **a, t_node **b, int n, t_benchmark *count)
{
	t_node	*min;

	while (*a)
	{
		min = find_min(*a);
		while ((*a)->nbr != min->nbr)
			ra(&a, 0, &count);
		pb(&b, &a, 0, &count);
	}
	while (*b)
		pa(&a, &b, 0, &count);
	if (*a && (*a)->bench)
		ft_bench(n, count);
	free(count);
}
