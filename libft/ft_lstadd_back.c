/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caperale <caperale@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:48:23 by caperale          #+#    #+#             */
/*   Updated: 2026/05/21 14:09:48 by caperale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ongoing;

	if (!lst || !new)
		return ;
	ongoing = *lst;
	if (*lst)
	{
		while (ongoing->next)
			ongoing = ongoing->next;
		ongoing->next = new;
	}
	else
		*lst = new;
}
