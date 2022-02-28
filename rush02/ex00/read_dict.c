/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:56:51 by afelten           #+#    #+#             */
/*   Updated: 2022/02/20 11:40:42 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	fill_dict(char **dict, char *line);
int		check_nbr_dict(char **dict, int size);

int	get_next_line(int fd, char **line)
{
	char	buff[2];
	char	*cpy;
	int		size;

	buff[1] = 0;
	size = 1;
	*line = malloc(size * sizeof(char));
	*line[0] = 0;
	while (read(fd, buff, 1) > 0)
	{
		cpy = malloc(size * sizeof(char));
		ft_strncpy(cpy, *line, size);
		free(*line);
		size++;
		*line = malloc(size * sizeof(char));
		ft_strncpy(*line, cpy, size - 1);
		free(cpy);
		ft_strncat(*line, buff, 1);
		if (buff[0] == '\n')
			break ;
	}
	return (size);
}

int	check_line_nbr(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != ' ' && line[i] != ':')
		return (0);
	if (line[i] == ' ')
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] != ':')
			return (0);
	}
	while (line[i] == ' ')
		i++;
	if (line[i] < 32 || line[i] > 126)
		return (0);
	while (line[i] > 31 && line[i] <= 126)
		i++;
	if (line[i] != '\n')
		return (0);
	return (2);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] >= '0' && line[0] <= '9')
		return (check_line_nbr(line));
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	read_dict(char **dict, char *file)
{
	int		fd;
	int		check;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line) > 1)
	{
		check = check_line(line);
		if (!check)
			return (0);
		else if (check == 2)
			fill_dict(dict, line);
		free(line);
	}
	free(line);
	return (check_nbr_dict(dict, 41));
}
