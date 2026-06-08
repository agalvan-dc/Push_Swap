/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caperale <caperale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:09:54 by caperale          #+#    #+#             */
/*   Updated: 2026/06/08 11:09:56 by caperale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	rotate(t_node ***stack)
{
	t_node	*last_node;

	if (!*stack || !**stack || !(**stack)->next)
		return ;
	last_node = find_last(**stack);
	last_node->next = **stack;
	**stack = (**stack)->next;
	(**stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_node ***a, bool print, t_benchmark **count)
{
	rotate(a);
	(*count)->nra += 1;
	(*count)->total += 1;
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_node ***b, bool print, t_benchmark **count)
{
	rotate(b);
	(*count)->nrb += 1;
	(*count)->total += 1;
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_node ***a, t_node ***b, bool print, t_benchmark **count)
{
	rotate(a);
	rotate(b);
	(*count)->nrr += 1;
	(*count)->total += 1;
	if (!print)
		ft_printf("rr\n");
}
