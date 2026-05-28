/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:10:19 by cperales          #+#    #+#             */
/*   Updated: 2026/05/28 10:10:52 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
// manda el ultimo elemento arriba
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool print,t_benchmark *count)
{
	reverse_rotate(a);
	count->nrra += 1;
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print, t_benchmark *count)
{
	reverse_rotate(b);
	count->nrrb += 1;
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print, t_benchmark *count)
{
	reverse_rotate(a);
	reverse_rotate(b);
	count->nrr += 1;
	if (!print)
		ft_printf("rrr\n");
}
