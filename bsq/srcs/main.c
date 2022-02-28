/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:38:09 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/23 21:36:55 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_input(char *std_input, int params_line, char vide, char obs)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (std_input[i])
	{
		if (std_input[i] == '\n')
			count ++;
		if (std_input[i] != vide && std_input[i]
			!= obs && std_input[i] != '\n' && count != 0)
			return (0);
		i++;
	}
	if (count - 1 == params_line)
		return (1);
	return (0);
}

int	ft_complen(char *std_input, int params_line, char vide, char obs)
{
	int	j;
	int	prev_j;
	int	size;
	int	i;

	size = 0;
	j = 0;
	i = 0;
	if (!check_input(std_input, params_line, vide, obs))
		return (0);
	j = ft_incremente_j(j, std_input);
	prev_j = ft_incremente_j(j, std_input);
	size = prev_j - j;
	while (i < params_line)
	{
		prev_j = j;
		j = ft_incremente_j(j, std_input);
		if (j - prev_j != size)
			return (0);
		i++;
	}
	return (1);
}

char	**creat_map(char *std_input, char **map, int params_line, char *param)
{
	int	i;
	int	j;
	int	nb_line_map;
	int	total_char;

	nb_line_map = 0;
	j = 0;
	if (!ft_complen(std_input, params_line, param[0], param[1]))
		return (0);
	if (param[0] == param[1] || param[2] == param[1] || param[0] == param[2])
		return (0);
	map[params_line] = 0;
	j = ft_incremente_j(j, std_input);
	total_char = j - 1;
	while (nb_line_map < params_line)
	{
		i = 0;
		j = ft_incremente_j(j, std_input);
		map[nb_line_map] = malloc(sizeof(char) * (j / (nb_line_map + 1) + 1));
		while (++total_char && total_char < j - 1)
			map[nb_line_map][i++] = std_input[total_char];
		map[nb_line_map++][i] = '\0';
	}
	free(std_input);
	return (map);
}

int	second(char **params)
{
	char	*std_input;
	int		params_line;
	char	**map;

	get_next_line_stdin(0, &std_input);
	params_line = ft_get_params(std_input, params);
	if (params_line == 0)
	{
		ft_putstr("map error\n");
		return (0);
	}
	map = malloc(sizeof(char *) * (params_line + 1));
	map = creat_map(std_input, map, params_line, *params);
	if (map == 0)
	{
		ft_putstr("map error\n");
		return (0);
	}
	map = ft_find_big_square(map, *params);
	ft_display(map);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**map;
	char	*params;
	int		i;

	params = malloc(sizeof(char) * 3);
	i = 1;
	if (argc == 1)
		second(&params);
	while (i < argc)
	{
		map = parsing(argv[i], &params);
		if (map != 0)
		{
			map = ft_find_big_square(map, params);
			ft_display(map);
			if (i < argc - 1)
				ft_putstr("\n");
		}
		i++;
	}
	free(params);
}
