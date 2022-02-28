/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:30:50 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/20 11:40:59 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_atoi_spe(char *str, unsigned int *nbr);
int		read_dict(char **dict, char *file);
int		print_number_str(char **dict, unsigned int nbr, int global);
void	initialize_dict(char **dict, int size);
void	free_dict(char **dict, int size);
int		get_next_line(int fd, char **line);

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
		if (buff[0] == '\n')
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

void	call_functions(char **dict, char *file, char *nbr)
{
	unsigned int	num;
	int				to_free;

	to_free = 0;
	if (!nbr)
	{
		get_next_line_stdin(0, &nbr);
		to_free = 1;
	}
	if (!ft_atoi_spe(nbr, &num))
		write(2, "Error\n", 6);
	else
	{
		if (read_dict(dict, file))
			print_number_str(dict, num, 1);
		else
			write(2, "Dict Error\n", 11);
	}
	if (to_free)
		free(nbr);
}

int	main(int argc, char **argv)
{
	char			*tab[41];

	initialize_dict(tab, 41);
	if (argc == 1)
		call_functions(tab, "numbers.dict", 0);
	else if (argc == 2)
	{
		call_functions(tab, "numbers.dict", argv[1]);
	}
	else if (argc == 3)
	{
		call_functions(tab, argv[1], argv[2]);
	}
	free_dict(tab, 41);
}
