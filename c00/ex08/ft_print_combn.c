/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:05:11 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/03 14:19:29 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_ascending(int *tab, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < (n - 1))
	{
		j = i + 1;
		if (tab[i] >= tab[j])
			return (0);
		i++;
	}
	return (1);
}

void	ft_display(int *tab, int n)
{
	int	i;

	i = 0;
	while (i <= (n - 1))
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != (10 - n))
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	tab[8];
	int	i;
	int	k;

	i = -1;
	if (n > 0 && n < 10)
	{
		while (i++ < (n - 1))
			tab[i] = i;
		while (tab[0] <= (10 - n))
		{
			if (is_ascending(tab, n))
				ft_display(tab, n);
			tab[n - 1]++;
			k = 1;
			while (tab[n - k] == 10 && n > 1)
			{
				tab[n - k - 1]++;
				tab[n - k] = 0;
				k++;
			}
		}
	}
}
