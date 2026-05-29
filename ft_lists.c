/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 05:59:39 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/30 01:15:35 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack_node *ft_stacknew(void *content, bool bench)
{
	t_stack_node *node;

	node = malloc(sizeof(t_stack_node *));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->above_median = false;
	node->bench = bench;
	node->parse = false;
	node->has_been_lowest = false;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	node->push_cost = 0;
	node->target_node = NULL; 
	return(node);
}
t_stack_node *ft_stackadd_last(t_stack_node **stack, t_stack_node *last)
{
	t_stack_node *cur;

	if (!stack || !last)
		return ;
	cur = *stack;
	if (!*stack)
	{
		*stack = last;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = last;
	return ;
}
t_stack_node *ft_lstlast(t_stack_node *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}
int	ft_stacksize(t_stack_node *node)
{
	t_stack_node *cur;
	int	i;

	i = 0;
	cur = node;
	while (cur)
	{
		++i;
		cur = cur->next;
	}
	return (i);
}
