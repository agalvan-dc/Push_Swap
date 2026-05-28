/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 05:14:39 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/28 06:28:09 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_list_stack(t_stack_node **a, t_stack_node *last, char **m, size_t *i)
{
	last = ft_stacknew(m[*i]);
	ft_stackadd_back(a, last);
	++(*i);
}

void	ft_stack_stack(t_stack_node **a, char **m, int n)
{
	size_t			i;
	t_stack_node	*last;

	i = 1;
	if (!n)
	{
		*a = ft_stacknew(m[0]);
		while (m[i])
			ft_list_stack(a, last, m, &i);
		return ;
	}
	if (ft_check_mode(m[1]) && ft_check_mode(m[2]))
	{
		*a = ft_stacknew(m[3]);
		while (m[i])
			ft_list_stack(a, last, m, &i);
		return ;
	}
	*a = ft_stacknew(m[2]);
	while (m[i])
		ft_list_stack(a, last, m, &i);
	return ;
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
	ft_stack_stack(a, argv, 1);
}
