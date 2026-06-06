/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 05:59:39 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/04 05:21:43 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*ft_stacknew(int content, bool bench)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
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
	return (node);
}

t_node	*ft_stackadd_back(t_node **stack, t_node *last)
{
	t_node	*cur;

	if (!stack || !last)
		return (NULL);
	cur = *stack;
	if (!*stack)
	{
		*stack = last;
		return (*stack);
	}
	while (cur->next)
		cur = cur->next;
	cur->next = last;
	return (last);
}

t_node	*ft_lstlast(t_node *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}

int	ft_stacksize(t_node *node)
{
	t_node		*cur;
	size_t		i;

	i = 0;
	cur = node;
	while (cur)
	{
		++i;
		cur = cur->next;
	}
	return (i);
}

size_t	ft_argv_len(char **argv)
{
	size_t	i;

	i = 0;
	if (!argv)
		return (i);
	while (argv[i])
		i++;
	return (i);
}
