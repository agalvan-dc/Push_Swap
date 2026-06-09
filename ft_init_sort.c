/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:34:15 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/09 16:11:36 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_parsing_selection(char **argv, t_node **a, t_node **b)
{
	if ((*a)->parse)
	{
		if (!ft_strncmp(argv[1], "--simple", ft_strlen(argv[1])))
			ft_simple_sort(a, b, 1, ft_init_bench(*a));
		else if (!ft_strncmp(argv[1], "--medium", ft_strlen(argv[1])))
			ft_chunk_sort(a, b, 2, ft_init_bench(*a));
		else if (!ft_strncmp(argv[1], "--complex", ft_strlen(argv[1])))
			ft_ksort(a, b, 3, ft_init_bench(*a));
		else if (!ft_strncmp(argv[1], "--adaptative", ft_strlen(argv[1])))
			ft_parse_options(2, argv, a, b);
		else
			ft_adaptative_sort(argv, a, b);
	}
	else if (!ft_strncmp(argv[2], "--simple", ft_strlen(argv[2])))
		ft_simple_sort(a, b, 1, ft_init_bench(*a));
	else if (!ft_strncmp(argv[2], "--medium", ft_strlen(argv[2])))
		ft_chunk_sort(a, b, 2, ft_init_bench(*a));
	else if (!ft_strncmp(argv[2], "--complex", ft_strlen(argv[2])))
		ft_ksort(a, b, 3, ft_init_bench(*a));
	else if (!ft_strncmp(argv[2], "--adaptative", ft_strlen(argv[2])))
		ft_parse_options(2, argv, a, b);
	else
		ft_adaptative_sort(argv, a, b);
}

void	ft_adaptative_sort(char **argv, t_node **a, t_node **b)
{
	if ((*a)->low_sort == 1)
		ft_sort_two(a, 0, ft_init_bench(*a));
	else if ((*a)->low_sort == 2)
		ft_sort_three(a, 0, ft_init_bench(*a));
	else if ((*a)->low_sort == 3)
		ft_sort_five(a, b, 0, ft_init_bench(*a));
	else
	{
		if (ft_disorder_tendency(argv) < 0.2)
			ft_simple_sort(a, b, 4, ft_init_bench(*a));
		else if (ft_disorder_tendency(argv) < 0.5)
			ft_chunk_sort(a, b, 5, ft_init_bench(*a));
		else
			ft_ksort(a, b, 6, ft_init_bench(*a));
	}
}

int	ft_bench_option(char *s1, char *s2)
{
	if (!ft_strncmp(s1, "--bench", ft_strlen(s1)))
		return (1);
	else if (!ft_strncmp(s2, "--bench", ft_strlen(s2)))
		return (1);
	return (0);
}
