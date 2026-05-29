/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:50:55 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/29 17:05:23 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.c"

bool ft_above_median(t_stack_node *a)
{
	t_stack_node	*aux;
	int				push_cost_up;
	int				push_cost_down;
	
	aux = a;
	push_cost_down = 0;
	push_cost_up = 0;
	while (aux)
	{
		aux = aux->prev;
		push_cost_up += 1;
	}
	while (a)
	{
		a = a->next;
		push_cost_down += 1;
	}
	if (push_cost_down < push_cost_up)
		return (false);
	return (true);
}


void	ft_arrange(t_stack_node *a, t_stack_node *b, t_benchmark *count)
{
	
	while (b)
	{
		ft_move_node_to_top(find_max(b), ft_above_median(b));
		pa(a, b, 1, count);
		b = b->next;
	}
}

void	ft_ksort(t_stack_node *a, t_stack_node *b, t_benchmark *count)
{
	int				k;
	t_stack_node	*current;

	k = ft_sqrt(ft_stacksize(a)) * 4.12;
	ft_current_index(a);
	current = a;
	while (current)
	{
		current = a->next;
		if (a->index > ft_stacksize(b) + k)
		{
			pb(a, b, 1, count);
			rb(b, 1, count);
		}
		else if (a->index > ft_stacksize(b))
			pb(a, b, 1, count);
		else
			ra(a, 1, count);
	}
	ft_arrange(a, b, count);
}
