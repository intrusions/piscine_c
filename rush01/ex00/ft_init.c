/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:31:31 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/13 18:10:08 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_putchar(char c);

/*
function to put input in a 2d array
*/

int	ft_convert_input(int **input, char *argv)
{
	int		x;
	int		y;
	int		k;

	x = 0;
	k = 0;
	y = 0;
	while (y <= 32)
	{
		input[x][k] = argv[y] - 48;
		y += 2;
		k++;
		if (y == 8 || y == 16 || y == 24)
		{
			x++;
			k = 0;
		}
	}
	return (1);
}
/*
function to print all the elements in our final array
*/

void	ft_print_tab(int **tab)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_putchar(tab[x][y] + 48);
			if (!(x == 3))
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
/*
function to initialize an 4x4 array with malloc and put 0 in all values
*/

int	**ft_init(void)
{
	int		x;
	int		y;
	int		**tab;

	x = 0;
	tab = malloc(sizeof(int *) * 4);
	if (!tab)
		return (0);
	while (x < 4)
	{
		tab[x] = malloc((sizeof(int) * 4));
		if (!tab[x])
			return (0);
		x++;
	}
	x = 0;
	while (x < 4)
	{
		y = -1;
		while (y++ < 4)
			tab[x][y] = 0;
		x++;
	}
	return (tab);
}
/*function to check if params are valid 
(16 int, between 0 and 4, separed by spaces)*/

int	ft_check_params(int argc, char **argv)
{
	int		x;
	int		y;

	x = 0;
	y = 1;
	if (ft_strlen(argv[1]) == 31 && argc == 2)
	{
		while (argv[1][x] >= '1' && argv[1][x] <= '4' && x <= 30)
			x += 2;
		while (argv[1][y] == ' ' && argv[1][y] && y <= 29)
			y += 2;
		if (!(x == 32 && y == 31))
			return (0);
	}
	else
		return (0);
	return (1);
}

/*free memory*/
int	ft_free(int **tab)
{
	int		i;

	i = -1;
	while (i++ < 4)
		free(tab[i]);
	free(tab);
	return (0);
}
