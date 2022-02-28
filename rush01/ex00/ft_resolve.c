/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:48:56 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/13 15:50:58 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_solution(int **tab, int **input);
int	ft_strlen(char *str);

/*
function that checks if we can put our number in the actual case, 
check on the columns and the lines if we dont have the same number
*/

int	ft_check_column(int index, int nbr, int	**tab)
{
	int		x;
	int		y;
	int		i;

	x = index / 4;
	y = index % 4;
	i = 0;
	while (i >= 0 && i <= index / 4 - 1)
	{
		if (tab[i][y] == nbr)
			return (0);
		i++;
	}
	i = 0;
	while (i >= 0 && i <= index % 4 - 1)
	{
		if (tab[x][i] == nbr)
			return (0);
		i++;
	}
	return (1);
}

/*
recursive function to solve the algorithmic problemes
*/

int	ft_resolve(int **tab, int index, int **input)
{
	int		n;
	int		result;

	n = 1;
	result = 0;
	while (n <= 4 && result == 0)
	{
		if (ft_check_column(index, n, tab))
		{
			tab[index / 4][index % 4] = n;
			if (index == 15)
				return (ft_check_solution(tab, input));
			else
				result = ft_resolve(tab, index + 1, input);
		}
		n++;
	}
	return (result);
}
