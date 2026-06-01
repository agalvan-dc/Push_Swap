/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:18:59 by cperales          #+#    #+#             */
/*   Updated: 2026/05/28 10:12:26 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	swap(t_stack_node **head)
		// cambia el primer y el segundo elemento de un stack
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a, bool print, t_benchmark *count)
{
	swap(a);
	count->nsa += 1;
	count->total += 1;
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print, t_benchmark *count)
{
	swap(b);
	count->nsb += 1;
	count->total += 1;
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print, t_benchmark *count)
{
	swap(a);
	swap(b);
	count->nss += 1;
	count->total += 1;
	if (!print)
		ft_printf("ss\n");
}
