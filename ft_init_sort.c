/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:34:15 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/30 01:10:12 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

ft_parsing_selection(char **argv, t_stack_node *a, t_stack_node *b, t_benchmark *count) //revisar opciones
{
	if (a->parse)
	{
		if (ft_strncmp(argv[1], "--simple", ft_strlen(argv[1])))
			ft_simple_sort(a, b, ft_bench_init());
		else if (ft_strncmp(argv[1], "--medium", ft_strlen(argv[1])))
			ft_chunk_sort(a, b, ft_bench_init());
		else if (ft_strncmp(argv[1], "--complex", ft_strlen(argv[1])))
			ft_ksort(a, b, ft_bench_init());
		else if (ft_strncmp(argv[1], "--adaptative", ft_strlen(argv[1])))
			ft_parse_options(2, argv, a, ft_bench_init());
	}
	if (ft_strncmp(argv[2], "--simple", ft_strlen(argv[2])))
		ft_simple_sort(a, b, ft_bench_init());
	else if (ft_strncmp(argv[2], "--medium", ft_strlen(argv[2])))
		ft_chunk_sort(a, b, ft_bench_init());
	else if (ft_strncmp(argv[2], "--complex", ft_strlen(argv[2])))
		ft_ksort(a, b, ft_bench_init());
	else if (ft_strncmp(argv[2], "--adaptative", ft_strlen(argv[2])))
		ft_parse_options(2, argv, a, b,ft_bench_init());
}

ft_alternative_sort(char **argv, t_stack_node *a, t_stack_node *b)
{
	if (ft_disorder_tendency(argv) < 0.2)
			ft_simple_sort(a, b, ft_bench_init());
	else if (ft_disorder_tendency(argv) < 0.5)
		ft_chunk_sort(a, b, ft_bench_init());
	else
			ft_ksort(a, b);
}
int	ft_bench_option(char *s1, char *s2)
{
	if (!ft_strncmp(s1, "--bench", ft_strlen(s1)))
		return (1);
	if (ft_strncmp(s2, "--bench", ft_strlen(s2)))
		return (1);
	return (0);
}
