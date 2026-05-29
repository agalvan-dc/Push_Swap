/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 05:17:41 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/30 01:07:46 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_parse_errors(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		if (!ft_check_args(ft_split(argv[1], ' ')))
		{
			write(2, "Error\n", 6);
			return (1);
		}
	else if (argc == 3) //comprueba que --bench --adaptive son validos
		if (!ft_check_flags(argv))
		{
			write(2, "Error\n", 6);
			return (1);
		}
	else if (argc > 3) //splitea args, comprueba flags y trimea nodos
		if (!ft_check_all(argv))
		{
			write(2, "Error\n", 6);
			return (1);
		}
}

void	ft_parse_options(int argc, char **argv, t_stack_node *a, t_stack_node *b)
{
	if (argc == 2)
		ft_adaptive_sort(argv, a, b);
	else if (argc == 3)
	{
		if (ft_strncmp(argv[1], "--bench", ft_strlen(argv[1])))
			ft_parse_options(2, argv, a, b);
		else
			ft_parse_modes(argv, a, b, 0);
	}
	else if (!ft_strncmp(argv[1], "--bench", ft_strlen(argv[1])))
		ft_parse_modes(argv, a, b, 0);
	else 
		ft_parse_modes(argv, a, b, 1);
}

void	ft_parse_modes(char **argv, t_stack_node *a, t_stack_node *b, int n)
{
	if (!n)
	{
		a->parse = true;
		ft_parsing_selection(argv, a, b, ft_init_bench());
	}
	else
		ft_parsing_selection(argv, a, b, ft_init_bench());
}
