/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:10:19 by cperales          #+#    #+#             */
/*   Updated: 2026/06/02 20:56:42 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	reverse_rotate(t_node **stack)
// manda el ultimo elemento arriba
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_node **a, bool print, t_benchmark *count)
{
	reverse_rotate(a);
	count->nrra += 1;
	count->total += 1;
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_node **b, bool print, t_benchmark *count)
{
	reverse_rotate(b);
	count->nrrb += 1;
	count->total += 1;
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, bool print, t_benchmark *count)
{
	reverse_rotate(a);
	reverse_rotate(b);
	count->nrrr += 1;
	count->total += 1;
	if (!print)
		ft_printf("rrr\n");
}
