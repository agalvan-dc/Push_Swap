/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caperale <caperale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:10:01 by caperale          #+#    #+#             */
/*   Updated: 2026/06/08 11:10:02 by caperale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	swap(t_node ***head)
{
	if (*head || !**head || !(**head)->next)
		return ;
	**head = (**head)->next;
	(**head)->prev->prev = **head;
	(**head)->prev->next = (**head)->next;
	if ((**head)->next)
		(**head)->next->prev = (**head)->prev;
	(**head)->next = (**head)->prev;
	(**head)->prev = NULL;
}

void	sa(t_node ***a, bool print, t_benchmark **count)
{
	swap(a);
	(*count)->nsa += 1;
	(*count)->total += 1;
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_node ***b, bool print, t_benchmark **count)
{
	swap(b);
	(*count)->nsb += 1;
	(*count)->total += 1;
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_node ***a, t_node ***b, bool print, t_benchmark **count)
{
	swap(a);
	swap(b);
	(*count)->nss += 1;
	(*count)->total += 1;
	if (!print)
		ft_printf("ss\n");
}
