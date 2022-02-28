/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:38:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/02/23 21:15:27 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

//structure
typedef struct s_var
{
	int	i;
	int	j;
	int	x;
	int	x_max;
	int	y;
	int	y_max;
	int	size;
	int	size_max;
}	t_var;
//utils.c
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_is_numeric(char str);
int		free_line(char *str);

//parsing.c
char	**parsing(char *file, char *params[3]);
char	*parameters(char *file, int *nb_lines, char *params[3]);
char	*get_parameters(char *file, int count_char, int *nb_lines,
			char *params[3]);

//parsing_map.c
char	**parsing_map(char *file, int nb_lines, char *params);
char	*file_desciptor_cop(int fd, int fc);
char	**map_is_valid(char **map, char *params);
int		ft_count_lines(char *file, int nb_lines);
int		ft_is_params(char c, char *params, int *trigger);

//ft_display.c
void	ft_display(char **map);

//ft_find_big_square.c
char	**ft_find_big_square(char **map, char *params);
int		check_size(char **map, t_var *var, char *params);
int		ft_is_obstacle(char c, char *params);
int		ft_check_last_column(int size, t_var *var, char **map, char *params);
int		ft_check_last_row(int size, t_var *var, char **map, char *params);
char	**put_square_in_map(char **map, int nb_row, int nb_column,
			char *params);
// utils2.c
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strncat(char *dest, char *src, unsigned int nb);

// ft_stdin.c
int		get_next_line_stdin(int fd, char **line);
int		ft_get_params(char *str_input, char **params);
int		check_params_stdin(char *std_input, char params, char params2);
int		ft_incremente_j(int j, char *std_input);
#endif
