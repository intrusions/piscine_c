/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:38:36 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/21 15:44:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*check_parameters(char *first_line, int count_char, int *nb_lines,
		char *params[3])
{
	int	i;

	i = 0;
	*nb_lines = ft_atoi(first_line);
	if (*nb_lines == 0)
		free_line(first_line);
	while (ft_is_numeric(first_line[i]))
		i ++;
	if (count_char - i != 3)
		free_line(first_line);
	if (first_line[i] == first_line[i + 2]
		|| first_line[i + 1] == first_line[i + 2]
		|| first_line[i] == first_line[i + 1])
		free_line(first_line);
	(*params)[0] = first_line[i];
	(*params)[1] = first_line[i + 1];
	(*params)[2] = first_line[i + 2];
	free(first_line);
	return (*params);
}

char	*get_parameters(char *file, int count_char, int *nb_lines,
		char *params[3])
{
	char	*first_line;
	char	buffer[1];
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	first_line = malloc(sizeof(char) * (count_char + 1));
	first_line[count_char] = 0;
	if (!first_line)
		return (0);
	while (i < count_char)
	{
		read(fd, buffer, 1);
		first_line[i] = buffer[0];
		i ++;
	}
	close(fd);
	return (check_parameters(first_line, count_char, nb_lines, params));
}

char	*parameters(char *file, int *nb_lines, char *params[3])
{
	char	buffer[1];
	int		fd;
	int		ret;
	int		count_char;

	count_char = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, buffer, 1);
	while (ret && buffer[0] != '\n')
	{
		ret = read(fd, buffer, 1);
		count_char += 1;
	}
	close(fd);
	return (get_parameters(file, count_char, nb_lines, params));
}

char	**parsing(char *file, char *params[3])
{
	char	**map;
	char	*first_line;
	int		nb_lines;

	first_line = parameters(file, &nb_lines, params);
	if (first_line == 0)
	{
		ft_putstr("map error\n");
		return (0);
	}
	map = parsing_map(file, nb_lines, first_line);
	if (map == 0)
	{
		free(map);
		ft_putstr("map error\n");
		return (0);
	}
	return (map);
}
