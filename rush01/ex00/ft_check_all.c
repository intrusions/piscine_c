/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:31:09 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/13 18:07:35 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*check if views are correct, left to the right*/

int	ft_check_left(int **tab, int *left)
{
	int		x;
	int		count;
	int		y;
	int		max;

	y = 0;
	while (y < 4)
	{
		count = 1;
		x = 0;
		max = tab[x][y];
		while (x < 4)
		{
			if (max < tab[x][y])
			{
				max = tab[x][y];
				count++;
			}
			x++;
		}
		if (count != left[y])
			return (0);
		y++;
	}
	return (1);
}
/*check if views are correct, right to the left*/

int	ft_check_right(int **tab, int *right)
{
	int		x;
	int		count;
	int		y;
	int		max;

	y = 0;
	while (y < 4)
	{
		count = 1;
		x = 3;
		max = tab[x][y];
		while (x >= 0)
		{
			if (max < tab[x][y])
			{
				max = tab[x][y];
				count++;
			}
			x--;
		}
		if (count != right[y])
			return (0);
		y++;
	}
	return (1);
}

/*
check if views are correct, top to bottom
*/

int	ft_check_top(int **tab, int *top)
{
	int		x;
	int		count;
	int		y;
	int		max;

	x = 0;
	while (x < 4)
	{
		count = 1;
		y = 0;
		max = tab[x][y];
		while (y < 4)
		{
			if (max < tab[x][y])
			{
				max = tab[x][y];
				count++;
			}
			y++;
		}
		if (count != top[x])
			return (0);
		x++;
	}
	return (1);
}

/*
check if views are correct, bottom to top
*/

int	ft_check_bottom(int **tab, int *top)
{
	int		x;
	int		count;
	int		y;
	int		max;

	x = 0;
	while (x < 4)
	{
		count = 1;
		y = 3;
		max = tab[x][y];
		while (y >= 0)
		{
			if (max < tab[x][y])
			{
				max = tab[x][y];
				count++;
			}
			y--;
		}
		if (count != top[x])
			return (0);
		x++;
	}
	return (1);
}

/*
call all the functions as the same time to check array
*/

int	ft_check_solution(int **tab, int **input)
{
	if (ft_check_top(tab, input[0]) && ft_check_bottom(tab, input[1])
		&& ft_check_left(tab, input[2]) && ft_check_right(tab, input[3]))
		return (1);
	else
		return (0);
	return (0);
}
