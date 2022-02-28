/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:05:03 by afelten           #+#    #+#             */
/*   Updated: 2022/02/20 10:13:16 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	initialize_dict(char **dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dict[i] = 0;
		i++;
	}
}

int	check_nbr_dict(char **dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!dict[i])
			return (0);
		i++;
	}
	return (1);
}

void	free_dict(char **dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (dict[i])
			free(dict[i]);
		i++;
	}
}
