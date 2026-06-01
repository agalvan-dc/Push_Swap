/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:50:56 by cperales          #+#    #+#             */
/*   Updated: 2026/05/28 10:09:57 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	rotate(t_stack_node **stack) // manda el primer elemento al fondo
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool print, t_benchmark *count)
{
	rotate(a);
	count->nra += 1;
	count->total += 1;
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print, t_benchmark *count)
{
	rotate(b);
	count->nrb += 1;
	count->total += 1;
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print, t_benchmark *count)
{
	rotate(a);
	rotate(b);
	count->nrr += 1;
	count->total += 1;
	if (!print)
		ft_printf("rr\n");
}
