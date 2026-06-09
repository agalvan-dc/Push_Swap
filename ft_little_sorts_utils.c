/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sorts_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:13:57 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/09 16:18:18 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*ft_find_sort(t_node **a)
{
	if (ft_stacksize(*a) == 2)
		return ((*a)->low_sort = 2);
	if (ft_stacksize(*a) == 3)
		return ((*a)->low_sort = 3);
	if (ft_stacksize(*a) == 5)
		return ((*a)->low_sort = 5);
	return ((*a)->low_sort = 0);
}
