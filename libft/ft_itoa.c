/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caperale <caperale@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:01:54 by caperale          #+#    #+#             */
/*   Updated: 2026/05/20 10:01:55 by caperale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int nb)
{
	size_t	cont;

	cont = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		cont++;
	while (nb != 0)
	{
		nb /= 10;
		cont++;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (!n)
		return (ft_strdup("0"));
	i = ft_count_digits(n);
	res = (char *)ft_calloc((i + 1), sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n *= (-1);
		res[0] = '-';
	}
	i--;
	while (n > 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (res);
}
