/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 05:14:39 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/30 01:17:33 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_list_stack(t_stack_node **a, char **m, size_t *i, bool bench)
{
	t_stack_node	*last;

	last = ft_stacknew(m[*i], bench);
	ft_stackadd_back(a, last);
	++(*i);
}

void	ft_stack_operations(t_stack_node **a, char **m, size_t i, int n)
{
	bool bench;

	bench = false;
	if (ft_bench_option(m[1], m[2]))
		bench = true;
	*a = ft_stacknew(m[n], bench);
	while (m[i])
		ft_list_stack(a, m, &i, bench);
}

void	ft_stack_stack(t_stack_node **a, char **m, int n)
{
	size_t	i;

	i = 1;
	if (!n)
		ft_stack_operations(a, m, i, 0);
	else if (!ft_check_mode(m[1]))
		ft_stack_operations(a, m, i, 1);
	else if (ft_check_mode(m[1]) && !ft_check_mode(m[2]))
		ft_stack_operations(a, m, i, 2);
	else if (ft_check_mode(m[1]) && ft_check_mode(m[2]))
		ft_stack_operations(a, m, i, 3);
}
int	ft_init_stack(t_stack_node **a, int argc, char **argv)
{
	char	**m;

	if (argc == 2)
	{
		m = ft_split(argv[1], ' ');
		if (!m)
			return (0);
		ft_stack_stack(a, m, 0);
	}
	else if (argc == 3)
	{
		m = ft_split(argv[2], ' ');
		if (!m)
			return (0);
		ft_stack_stack(a, m, 0);
	}
	else
		ft_stack_stack(a, argv, 1);
	return (1);
}
t_benchmark	ft_init_bench(void)
{
	t_benchmark 	count;

	count.nsa = 0;
	count.npa = 0;
	count.nss = 0;
	count.npa = 0;
	count.npb = 0;
	count.nra = 0;
	count.nrb = 0;
	count.nrr = 0;
	count.nrra = 0;
	count.nrrb = 0;
	return (count);
}
