/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:41:45 by caperale          #+#    #+#             */
/*   Updated: 2026/06/06 16:51:05 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_move_node_to_top(t_node **a, bool above_median, t_benchmark **count)
{
	if (above_median == true)
	{
		while (*a)
		{
			ra(&a, 0, count);
			*a = (*a)->prev;
		}
	}
	else if (above_median == false)
	{
		while (*a)
		{
			rra(&a, 0, count);
			*a = (*a)->next;
		}
	}
}

void	ft_move_node_to_top_b(t_node ***b, t_node *target,
	bool above_median, t_benchmark **count)
{
	while (**b != target)
	{
		if (above_median == true)
			rb(b, 0, count);
		else
			rrb(b, 0, count);
	}
}
