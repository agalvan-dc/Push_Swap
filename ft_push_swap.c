/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:55:27 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/06 19:03:54 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ft_parse_errors(argc, argv))
		return (1);
	if (!ft_init_stack(&a, argc, argv))
		return (1);
	ft_put_indexes(&a);
	ft_parse_options(argc, argv, &a, &b);
	ft_free_all(&a, &b);
	return (0);
}
