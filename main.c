/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:55:27 by agalvan-          #+#    #+#             */
/*   Updated: 2026/05/28 11:37:06 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if(ft_parse_errors(argc, argv))
		return (1);
	ft_init_stack(&a, argc ,argv);
	b = ft_stacknew();
	ft_parse_options(argc, argv, a, b);
	return (0);
}
