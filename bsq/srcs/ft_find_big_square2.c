/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_big_square2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:08:38 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/21 20:32:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_last_column(int size, t_var *var, char **map, char *params)
{
	int	i;
	int	finish;

	i = 0;
	finish = 0;
	while (i <= size && finish == 0)
	{
		if (!ft_is_obstacle(map[var->y + i][size + var->x], params))
			i++;
		else
			finish = 1;
	}
	return (finish);
}

int	ft_check_last_row(int size, t_var *var, char **map, char *params)
{
	int	i;
	int	finish;

	i = 0;
	finish = 0;
	while (i <= size && finish == 0)
	{
		if (!ft_is_obstacle(map[size + var->y][var->x + i], params))
			i++;
		else
			finish = 1;
	}
	return (finish);
}
