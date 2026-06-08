/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caperale <caperale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:58:54 by caperale          #+#    #+#             */
/*   Updated: 2026/06/08 12:58:56 by caperale         ###   ########.fr       */
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

t_node	*ft_stack_operations(char **m, size_t start, bool bench)
{
	t_node	*a;
	size_t	i;

	if (!m || !m[start])
		return (NULL);
	a = ft_stacknew(ft_atoi(m[start]), bench);
	i = start + 1;
	while (m[i])
		ft_list_stack(&a, m, &i, bench);
	return (a);
}

int	ft_init_stack(t_node **a, int argc, char **argv)
{
	char	**m;
	int		i;
	bool	bench;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
		i++;
	if (i == argc)
		return (0);
	bench = false;
	if (ft_bench_option(argv[1], argv[2]))
		bench = true;
	if (argc - i == 1)
	{
		m = ft_split(argv[i], ' ');
		if (!m)
			return (0);
		*a = ft_stack_operations(m, 0, bench);
		ft_free_array(m);
	}
	else
		*a = ft_stack_operations(argv, i, bench);
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
