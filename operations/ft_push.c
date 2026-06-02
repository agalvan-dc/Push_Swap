/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 03:05:46 by cperales          #+#    #+#             */
/*   Updated: 2025/05/25 03:05:46 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_node **a, t_node **b, bool print, t_benchmark *count) // push a
{
	push(b, a);
	count->npa += 1;
	count->total += 1;
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a, bool print, t_benchmark *count) // push b
{
	push(a, b);
	count->npb += 1;
	count->total += 1;
	if (!print)
		ft_printf("pb\n");
}
