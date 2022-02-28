/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_big_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:00:13 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/21 20:31:56 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_is_obstacle(char c, char *params)
{
	if (c == params[1])
		return (1);
	return (0);
}

int	check_size(char **map, t_var *var, char *params)
{
	int	nb_row;
	int	nb_column;
	int	size;
	int	finish;
	int	finish2;

	nb_row = 0;
	nb_column = 0;
	size = 0;
	finish = 0;
	finish2 = 0;
	while (map[nb_row] != 0)
		nb_row ++;
	while (map[0][nb_column] != 0)
		nb_column++;
	while ((size + var->y < nb_row && size + var->x < nb_column) && finish != 1)
	{
		finish = ft_check_last_row(size, var, map, params);
		finish2 = ft_check_last_column(size, var, map, params);
		if (finish == 0 && finish2 == 0)
			size++;
		else
			finish = 1;
	}
	return (size);
}

char	**ft_put_my_square(t_var var, char **map, char *params)
{
	while (var.i < var.size_max)
	{
		var.j = 0;
		while (var.j < var.size_max)
		{
			map[var.y_max + var.i][var.x_max + var.j] = params[2];
			var.j++;
		}
		var.i++;
	}
	return (map);
}

char	**put_square_in_map(char **map, int nb_row, int nb_column, char *params)
{
	t_var	var;

	var.i = 0;
	var.x = 0;
	var.y = 0;
	var.size_max = 0;
	while (var.y < nb_row && var.x < nb_column)
	{
		var.size = check_size(map, &var, params);
		if (var.size > var.size_max)
		{
			var.size_max = var.size;
			var.x_max = var.x;
			var.y_max = var.y;
		}
		var.x += 1;
		if (var.x == nb_column && var.y < nb_row - 1)
		{
			var.x = 0;
			var.y++;
		}
	}
	return (ft_put_my_square(var, map, params));
}

char	**ft_find_big_square(char **map, char *params)
{
	int	nb_row;
	int	nb_column;

	nb_row = 0;
	nb_column = 0;
	while (map[nb_row] != 0)
		nb_row ++;
	while (map[0][nb_column] != 0)
		nb_column++;
	map = put_square_in_map(map, nb_row, nb_column, params);
	return (map);
}
