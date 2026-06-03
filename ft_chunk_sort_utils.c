/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:41:45 by caperale          #+#    #+#             */
/*   Updated: 2026/06/02 19:48:27 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_move_node_to_top(t_node *a, bool above_median, t_benchmark *count)
{
	t_node	*current;

	current = a;
	if (above_median == true)
	{
		while (current)
		{
			ra(&a, 0, count);
			current = current->prev;
		}
	}
	else if (above_median == false)
	{
		while (current)
		{
			rra(&a, 0, count);
			current = current->next;
		}
	}
}
