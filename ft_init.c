/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:44:09 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/06 16:31:05 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_list_stack(t_node **a, char **m, size_t *i, bool bench)
{
	t_node	*last;

	last = ft_stacknew(ft_atoi(m[*i]), bench);
	ft_stackadd_back(a, last);
	++(*i);
}

t_node	*ft_stack_operations(char **m, size_t i, int n)
{
	t_node	*a;
	bool	bench;
	
	bench = false;
	if (ft_bench_option(m[1], m[2]))
		bench = true;
	a = ft_stacknew(ft_atoi(m[n]), bench);
	while (m[i])
		ft_list_stack(&a, m, &i, bench);
	return (a);
}

void	ft_stack_stack(t_node **a, char **m, int n)
{
	if (!n)
		*a = ft_stack_operations(m, 1, 0);
	else if (!ft_check_mode(m[1]))
		*a = ft_stack_operations(m, 2, 1);
	else if (ft_check_mode(m[1]) && !ft_check_mode(m[2]))
		*a = ft_stack_operations(m, 3, 2);
	else if (ft_check_mode(m[1]) && ft_check_mode(m[2]))
		*a = ft_stack_operations(m, 4, 3);
}

int	ft_init_stack(t_node **a, int argc, char **argv)
{
	char	**m;

	if (argc == 2)
	{
		m = ft_split(argv[1], ' ');
		if (!m)
			return (0);
		ft_stack_stack(a, m, 0);
		ft_free_array(m);
	}
	else if (argc == 3 && ft_check_mode(argv[1]))
	{
		 m = ft_split(argv[2], ' ');
		if (!m)
			return (0);
		ft_stack_stack(a, m, 0);
		ft_free_array(m);
	}
	else if (argc == 3)
		ft_init_stack(a, 0, argv);
	else
		ft_stack_stack(a, argv, 1);
	return (1);
}

t_benchmark	*ft_init_bench(t_node *a)
{
	t_benchmark	*count;

	count = (t_benchmark *)malloc(sizeof(t_benchmark));
	if (!count)
		return (NULL);
	count->nsa = 0;
	count->npa = 0;
	count->nss = 0;
	count->npa = 0;
	count->npb = 0;
	count->nra = 0;
	count->nrb = 0;
	count->nrr = 0;
	count->nrra = 0;
	count->nrrb = 0;
	count->nrrr = 0;
	count->total = 0;
	count->dt = ft_dissorder(a);
	return (count);
}
