/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:26:43 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/21 15:32:36 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_is_params(char c, char *params, int *trigger)
{
	if (c != params[0] && c != params[1])
		return (0);
	*trigger = 1;
	return (1);
}

char	**map_is_valid(char **map, char *params)
{
	int	i;
	int	len;
	int	j;
	int	trigger;

	trigger = 0;
	i = 0;
	len = ft_strlen(map[0]);
	while (map[i] != 0)
	{
		j = 0;
		if (ft_strlen(map[i]) != len)
			return (0);
		len = ft_strlen(map[i]);
		while (j < len)
		{
			if (ft_is_params(map[i][j], params, &trigger) == 0)
				return (0);
			j ++;
		}
		i ++;
	}
	if (trigger == 1)
		return (map);
	return (0);
}

int	ft_count_lines(char *file, int nb_lines)
{
	char	buffer[1];
	int		fd;
	int		ret;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, buffer, 1);
	while (ret)
	{
		if (buffer[0] == '\n')
			count ++;
		ret = read(fd, buffer, 1);
	}
	close(fd);
	if (count == nb_lines + 1)
		return (1);
	return (0);
}

char	*file_descriptor_cop(int fd, int fc)
{
	int		count;
	int		i;
	char	buffer[1];
	char	*line;

	count = 0;
	i = 0;
	read(fd, buffer, 1);
	while (buffer[0] != '\n')
	{
		count ++;
		read(fd, buffer, 1);
	}
	line = malloc(sizeof(char) * (count + 1));
	while (i < count + 1)
	{
		read(fc, buffer, 1);
		line[i] = buffer[0];
		i ++;
	}
	line[count] = 0;
	return (line);
}

char	**parsing_map(char *file, int nb_lines, char *params)
{
	char	**map;
	char	*first_line;
	int		i;
	int		fd;
	int		fc;

	i = 0;
	map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!map)
		return (0);
	map[nb_lines] = 0;
	if (ft_count_lines(file, nb_lines) == 0)
		return (0);
	fd = open(file, O_RDONLY);
	fc = open(file, O_RDONLY);
	first_line = file_descriptor_cop(fd, fc);
	free(first_line);
	while (i < nb_lines)
	{
		map[i] = file_descriptor_cop(fd, fc);
		i ++;
	}
	close(fd);
	close(fc);
	return (map_is_valid(map, params));
}
