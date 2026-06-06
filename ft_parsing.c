/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 05:17:41 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/06 00:00:26 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
int	ft_parse_errors(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && ft_check_mode(argv[1])))
		return (write(2, "Error\n", 6), 1);
	else if (argc == 2)
	{
		if (!ft_check_args(1 , ft_split(argv[1], ' ')))
			return (write(2, "Error\n", 6), 1);
	}
	else if (argc == 3)
	{
		if (ft_check_flags(argv))
			return (write(2, "Error\n", 6), 1);
	}
	else if (argc > 3)
	{
		if (!ft_check_all(argv))
			return (write(2, "Error\n", 6), 1);
	}
	return (0);
}

int	ft_check_duplicates(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1 + ft_check_number_options(argv, 1, 0);
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_parse_options(int argc, char **argv, t_node **a, t_node **b)
{
	if (ft_is_sorted(a) != 0)
	{
		if (argc == 2)
			ft_adaptative_sort(argv, a, b);
		else if (argc == 3)
		{
			if (!ft_strncmp(argv[1], "--bench", ft_strlen(argv[1])))
				ft_parse_options(2, argv, a, b);
			else
				ft_parse_modes(argv, a, b, 0);
		}
		else if (ft_strncmp(argv[1], "--bench", ft_strlen(argv[1])))
			ft_parse_modes(argv, a, b, 0);
		else
			ft_parse_modes(argv, a, b, 1);
	}
	else
		ft_printf("Stack is already sorted\n");
}

void	ft_parse_modes(char **argv, t_node **a, t_node **b, int n)
{
	if (!n)
	{
		(*a)->parse = true;
		ft_parsing_selection(argv, a, b);
	}
	else
		ft_parsing_selection(argv, a, b);
}

int	ft_parse_num(char *argv)
{
	size_t	j;

	j = 0;
	if (argv[j] == '-')
		j++;
	while (argv[j])
	{
		if (argv[j] && !(argv[j] >= '0' && argv[j] <= '9'))
			return (0);
		j++;
	}
	return (1);
}
