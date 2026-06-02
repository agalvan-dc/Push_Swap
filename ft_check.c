/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:47:05 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/02 22:50:23 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_args(char **argv)
{
	size_t	i;

	i = ft_check_number_options(argv, 1, 0);
	while (i <= ft_argv_len(argv) - ft_check_number_options(argv, 1, 0))
	{
		if (!(ft_parse_num(argv)))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_check_flags(char **argv)
{
	if (!(ft_strncmp(argv[1], "--complex", ft_strlen(argv[1]))))
	{
		if (!ft_check_args(ft_split(argv[2], ' ')))
			return (1);
	}
	else if (!(ft_strncmp(argv[1], "--adaptive", ft_strlen(argv[1]))))
	{
		if (!ft_check_args(ft_split(argv[2], ' ')))
			return (1);
	}
	return (0);
}

int	ft_check_flags(char **argv)
{
	if (!(ft_strncmp(argv[1], "--bench", ft_strlen(argv[1]))))
	{
		if (!ft_check_args(ft_split(argv[2], ' ')))
			return (1);
	}
	else if (!(ft_strncmp(argv[1], "--simple", ft_strlen(argv[1]))))
	{
		if (!ft_check_args(ft_split(argv[2], ' ')))
			return (1);
	}
	else if (!(ft_strncmp(argv[1], "--medium", ft_strlen(argv[1]))))
	{
		if (!ft_check_args(ft_split(argv[2], ' ')))
			return (1);
	}
	else if (ft_check_check_flags(argv))
		return (1);
	return (0);
}

int	ft_check_mode(char *argv)
{
	if (!(ft_strncmp(argv, "--bench", ft_strlen(argv))))
		return (1);
	 if (!(ft_strncmp(argv, "--simple", ft_strlen(argv))))
		return (1);
	if (!(ft_strncmp(argv, "--medium", ft_strlen(argv))))
		return (1);
	if (!(ft_strncmp(argv, "--complex", ft_strlen(argv))))
		return (1);
	if (!(ft_strncmp(argv, "--adaptive", ft_strlen(argv))))
		return (1);
	return (0);
}

int	ft_check_all(char **argv)
{
	size_t	i;

	i = ft_check_number_options(argv, 1, 0);
	if (!(ft_strncmp(argv[1], argv[2], ft_strlen(argv[1]))))
		return (0);
	else if (!(ft_check_mode(argv[1])) && !(ft_check_args(argv)))
		return (0);
	while (i < ft_argv_len(argv) - ft_check_number_options(argv, 1, 0))
	{
		if (!(ft_parse_num(argv)))
			return (0);
		++i;
	}
	return (1);
}
