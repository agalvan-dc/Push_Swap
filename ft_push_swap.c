/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:55:27 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/08 18:42:43 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**m;
	int		new_argc;

	a = NULL;
	b = NULL;
	m = ft_join_and_split(argc, argv);
	if (!m)
	{
		ft_printf("hello\n\n");
		return (1);
	}
	new_argc = ft_argv_len(m);
	if (ft_parse_errors(new_argc, m))
		return (free(m), 1);
	if (!ft_init_stack(&a, new_argc, m))
		return (free(m), 1);
	ft_put_indexes(&a);
	ft_parse_options(new_argc, m, &a, &b);
	ft_free_all(&a, &b);
	ft_free_array(m);
	return (0);
}
