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

size_t 	ft_check_number_options(char **argv, size_t n, size_t k)
{
	if (!ft_strncmp(argv[n], "--bench", ft_strlen(argv[n])))
		k += 1;
	else if (!ft_strncmp(argv[n], "--simple", ft_strlen(argv[n])))
		k += 1;
	else if (!ft_strncmp(argv[n], "--medium", ft_strlen(argv[n])))
		k += 1;
	else if (!ft_strncmp(argv[n], "--complex", ft_strlen(argv[n])))
		k += 1;
	else if (!ft_strncmp(argv[n], "--adaptive", ft_strlen(argv[n])))
		k += 1;
	if (n < 2)
		ft_check_number_options(argv, 2, k);
	return (k);
}

float	ft_check_individual_args(char **argv)
{
	float	mistakes;
	float	total_pairs;
	size_t	i;
	size_t	j;

	i = ft_check_number_options(argv, 1, 0);
	total_pairs = 0;
	mistakes = 0;
	while (i <= ft_strlen(*argv) - ft_check_number_options(argv, 1, 1))
	{
		j = i + 1;
		while (j <= ft_strlen(*argv) - ft_check_number_options(argv, 1, 1))
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
float	ft_dissorder(t_stack_node *a)
{
	int			*stack;
	char		**m;
	size_t		i;

	i = 0;
	stack = malloc(sizeof(int) * (ft_stacksize(a) + 1));
	m = malloc(sizeof(char *) * ft_stacksize(a) + 2);
	if (!stack || !m)
		return (0);
	while (a)
	{
		stack[i++] = a->nbr;
		a = a->next;
	}
	stack[i] = '\0';
	m[i + 2] = '\0';
	while(i + 1 > 0)
	{
		m[i + 1] = ft_itoa(stack[i]);
		--i;
	}
	m[0] = '0';
	return (ft_disorder_tendency(m));
}
