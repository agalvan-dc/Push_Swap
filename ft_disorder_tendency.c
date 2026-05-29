/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_tendency.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:57:25 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/30 01:22:29 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

float	ft_check_individual_args(char **argv)
{
	float	mistakes;
	float	total_pairs;
	size_t	i;
	size_t	j;

	i = 1;
	total_pairs = 0;
	mistakes = 0;
	while (i <= ft_strlen(*argv) - 1)
	{
		j = i + 1;
		while (j <= ft_strlen(*argv) - 1)
		{
			total_pairs += 1;
			if (argv[i] > argv[j])
				mistakes += 1;
		}
		++i;
	}
	return (mistakes / total_pairs);
}

float	ft_check_arg_args(char **argv)
{
	char	**m;

	m = ft_split(argv[1], ' ');
	if (!m)
		return (0);
	return (ft_check_individual_args(m));
}

float	ft_disorder_tendency(char **argv)
{
	if (ft_strlen(*argv) > 2)
		return (ft_check_individual_args(**argv));
	else if (ft_strlen(*argv) == 2)
		return (ft_check_arg_args(**argv));
	return (-1);
}
ft_dissorder(t_stack_node *a)
{


	
}