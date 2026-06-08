/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:41:45 by caperale          #+#    #+#             */
/*   Updated: 2026/06/08 17:07:04 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_move_node_to_top(t_node ***stack, t_node *target,
	bool above_median, t_benchmark **count)
{
	while (**stack != target)
	{
		if (above_median)
			ra(stack, 0, count);
		else
			rra(stack, 0, count);
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

void	ft_push_best_candidate(t_chunk *chunk)
{
	int	first_cost;
	int	second_cost;
	int	hold_first;
	int	hold_second;

	first_cost = ft_cost_of_push_on_first(
			**chunk->a, chunk->chunk_range, &hold_first);
	second_cost = ft_cost_of_push_on_second(
			**chunk->a, chunk->chunk_range, &hold_second);
	if (first_cost <= second_cost)
	{
		ft_move_first_to_top(chunk->a, hold_first, chunk->count);
		pb(chunk->b, chunk->a, 0, chunk->count);
	}
	else
	{
		ft_move_second_to_top(chunk->a, hold_second, chunk->count);
		pb(chunk->b, chunk->a, 0, chunk->count);
	}
}

int	ft_process_chunk(t_chunk *chunk)
{
	int	first_cost;
	int	hold_first;

	first_cost = ft_cost_of_push_on_first(
			**chunk->a, chunk->chunk_range, &hold_first);
	if (first_cost == -1)
	{
		chunk->chunk_range += chunk->chunk_size;
		return (0);
	}
	ft_push_best_candidate(chunk);
	if (**chunk->b
		&& (*(*chunk->b))->index
		< (chunk->chunk_range - (chunk->chunk_size / 2)))
		rb(chunk->b, 0, chunk->count);
	return (1);
}

void	ft_bench_launch()
{
	t_benchmark	*count;

	count = ft_init_bench(NULL);
	ft_bench(1 ,count);
	free(count);
	return ;
}
