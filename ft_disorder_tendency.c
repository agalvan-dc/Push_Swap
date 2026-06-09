/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder_tendency.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:57:25 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/09 19:45:42 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

size_t	ft_check_number_options(char **argv, size_t n, size_t k)
{
	if (!ft_strncmp(argv[n], "--bench", ft_strlen(argv[n])))
		k += 1;
	else if (!ft_strncmp(argv[n], "--simple", ft_strlen(argv[n])))
		k += 1;
	else if (!ft_strncmp(argv[n], "--medium", ft_strlen(argv[n])))
		k += 1;
	else if (!ft_strncmp(argv[n], "--complex", ft_strlen(argv[n])))
		k += 1;
	else if (!ft_strncmp(argv[n], "--adaptative", ft_strlen(argv[n])))
		k += 1;
	if (n < 2 && (ft_argv_len(argv) > 2))
		return (ft_check_number_options(argv, 2, k));
	return (k);
}

float	ft_check_individual_args(char **argv, size_t start)
{
	float	mistakes;
	float	total_pairs;
	size_t	i;
	size_t	j;

	total_pairs = 0;
	mistakes = 0;
	i = start;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			total_pairs += 1;
			if (ft_atoi(argv[i]) > ft_atoi(argv[j]))
				mistakes += 1;
			++j;
		}
		++i;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}

float	ft_disorder_tendency(char **argv)
{
	int		i;
	char	**m;
	float	res;

	i = 0;
	while (argv[i + 1] && argv[i + 1][0] == '-' && argv[i + 1][1] == '-')
		i++;
	if (!argv[i])
		return (0.0);
	if (!argv[i + 1])
	{
		m = ft_split(argv[i], ' ');
		if (!m)
			return (0.0);
		res = ft_check_individual_args(m, 0);
		ft_free_array(m);
		return (res);
	}
	return (ft_check_individual_args(argv, i));
}

float	ft_dissorder(t_node *a)
{
	char	**m;
	int		i;
	float	tendency;

	if (!a)
		return (0);
	m = malloc(sizeof(char *) * (ft_stacksize(a) + 1));
	if (!m)
		return (0);
	i = -1;
	while (a)
	{
		m[++i] = ft_itoa(a->nbr);
		if (!m[i])
		{
			while (i-- > 0)
				free(m[i]);
			return (free(m), 0);
		}
		a = a->next;
	}
	m[++i] = NULL;
	tendency = ft_disorder_tendency(m);
	return (ft_free_array(m), tendency);
}
