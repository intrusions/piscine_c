/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:24:34 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/23 21:27:54 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_next_line_stdin(int fd, char **line)
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
		if (buff[0] == '\0')
			break ;
		cpy = malloc(size * sizeof(char));
		ft_strncpy(cpy, *line, size);
		free(*line);
		size++;
		*line = malloc(size * sizeof(char));
		ft_strncpy(*line, cpy, size - 1);
		free(cpy);
		ft_strncat(*line, buff, 1);
	}
	return (size);
}

int	ft_get_params(char *str_input, char **params)
{
	int		i;
	int		j;
	int		k;
	int		result;

	i = 0;
	j = 0;
	k = -1;
	result = 0;
	while (str_input[j] != '\n' && str_input[j])
		j++;
	if (j < 4)
		return (0);
	while ((str_input[i] >= '0' && str_input[i] <= '9') && i < (j - 3))
	{
		result = result * 10 + (str_input[i] - '0');
		i++;
	}
	if (!(j - i == 3))
		return (0);
	while (++k < 3)
		(*params)[k] = str_input[i + k];
	return (result);
}

int	check_params_stdin(char *std_input, char params, char params2)
{
	int	i;

	i = -1;
	while (std_input[++i])
		if (params != std_input[i] && params2 != std_input[i])
			return (0);
	return (1);
}

int	ft_incremente_j(int j, char *std_input)
{
	while (std_input[j] != '\n' && std_input[j])
		j++;
	j++;
	return (j);
}
