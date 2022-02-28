/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:51:05 by afelten           #+#    #+#             */
/*   Updated: 2022/02/20 15:31:58 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

unsigned int	convert_index(int index)
{
	int	ret;
	int	i;

	if (index < 21)
		return (index);
	else if (index < 28)
		return ((index - 18) * 10);
	else if (index == 28)
		return (100);
	else
	{
		i = 0;
		ret = 1;
		while (i < index - 28)
		{
			ret *= 1000;
			i++;
		}
		return (ret);
	}
}

int	check_need_and(unsigned int nbr)
{
	int	i;

	i = 20;
	while (i < 100)
	{
		if (nbr - i == 0)
			return (0);
		i += 10;
	}
	return (1);
}

void	putnumber(char **dict, unsigned int nbr, int global, int i)
{
	ft_putstr(dict[i]);
	if (nbr > 0 && i < 28 && i > 19 && nbr < convert_index(20))
		write(1, "-", 1);
	else if (nbr > 0 || global == 0)
		write(1, " ", 1);
	if (nbr > 0 && i > 27 && nbr < convert_index(28) && check_need_and(nbr))
		write(1, "and ", 4);
}

void	print_number_str(char **dict, unsigned int nbr, int global)
{
	int				i;
	unsigned int	num;

	i = 31;
	if (nbr == 0)
		ft_putstr(dict[0]);
	else
	{
		while (nbr > 0 && i > 0)
		{
			num = 0;
			while (nbr >= convert_index(i))
			{
				nbr = nbr - convert_index(i);
				num++;
			}
			if (num > 1 || (num == 1 && i > 27))
				print_number_str(dict, num, 0);
			if (num > 0)
				putnumber(dict, nbr, global, i);
			i--;
		}
	}
	if (global == 1)
		write(1, "\n", 1);
}
