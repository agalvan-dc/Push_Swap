/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:56:53 by caperale          #+#    #+#             */
/*   Updated: 2026/06/06 18:06:23 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_sqrt(int nbr)
{
long result;

if (nbr <= 0)
		return (0);
	result = 0;
	while (result * result <= nbr)
		result++;
	return ((int)(result - 1));
}
