/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:14:50 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/06 16:26:28 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_free_all(t_node **a, t_node **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
}

void	ft_free_array(char **m)
{
	size_t	i;

	i = 0;
	if (!m)
		return ;
	while (m[i])
		free(m[i++]);
	free(m);
	return ;
}
