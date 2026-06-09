/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:48:51 by caperale          #+#    #+#             */
/*   Updated: 2026/06/09 17:29:21 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_two(t_node **a, int n, t_benchmark *count)
{
	sa(&a, 0, &count);
	if (*a && (*a)->bench)
		ft_bench(n, count);
	free(count);
}

static void	ft_sort_three_if(t_node **a, t_benchmark *count)
{
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
		sa(&a, 0, &count);
	else if ((*a)->nbr < (*a)->next->nbr
		&& (*a)->nbr > (*a)->next->next->nbr)
		rra(&a, 0, &count);
	else if ((*a)->nbr > (*a)->next->nbr
		&& (*a)->nbr > (*a)->next->next->nbr)
	{
		if ((*a)->next->nbr > (*a)->next->next->nbr)
		{
			sa(&a, 0, &count);
			rra(&a, 0, &count);
		}
		else if ((*a)->next->nbr < (*a)->next->next->nbr)
			ra(&a, 0, &count);
	}
	else if ((*a)->nbr < (*a)->next->nbr
		&& (*a)->nbr < (*a)->next->next->nbr)
	{
		rra(&a, 0, &count);
		sa(&a, 0, &count);
	}
}

void	ft_sort_three(t_node **a, int n, t_benchmark *count)
{
	ft_sort_three_if(a, count);
	if (*a && (*a)->bench)
		ft_bench(n, count);
	free(count);
}
