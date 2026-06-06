/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:21:35 by caperale          #+#    #+#             */
/*   Updated: 2026/06/06 13:15:01 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_lowest_on_a(t_node	***a, t_node	***b, t_benchmark **count)
{
	t_node	*current;
	t_node	*next;

	current = **a;
	while (current->next)
	{
		next = current->next;
		current = current->next;
		if (current->index < next->index && next != NULL)
			sa(a, 0, count);
		pb(b, a, 0, count);
	}
	current->has_been_lowest = true;
}

void	ft_lowest_on_b(t_node ***a, t_node ***b, t_benchmark **count)
{
	t_node	*current;

	current = **b;
	rb(b, 0, count);
	while (current->has_been_lowest != true)
	{
		current = current->next;
		pa(a, b, 0, count);
	}
}

int	ft_is_sorted(t_node **stack)
{
	t_node	*current;
	int		is_sorted;

	if (!stack || !*stack)
		return (0);
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
	while (ft_is_sorted(a) != 0)
	{
		ft_lowest_on_a(&a, &b, &count);
		ft_printf("%d\n", (*a)->index);
		pb(&b, &a, 0, &count);
		ft_lowest_on_b(&a, &b, &count);
		ft_printf("hello\n");
	}
	if ((*a)->bench)
		ft_bench(n, count);
	ft_free_all(a, b);
}
