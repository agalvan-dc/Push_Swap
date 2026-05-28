/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caperale <caperale@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:58:35 by caperale          #+#    #+#             */
/*   Updated: 2026/05/21 16:01:28 by caperale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dst;
	unsigned char *sr;
	size_t	i;

	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	i = 0;
	if (dst < sr && sr + n > dst)
	{

	}
}