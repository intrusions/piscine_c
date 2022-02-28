/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:20:46 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/22 04:20:26 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_left(int *tab, int length, int (*f)(int, int))
{
	int		i;

	i = 0;
	while (i < (length - 1))
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_right(int *tab, int length, int (*f)(int, int))
{
	int		i;

	i = 0;
	while (i < (length - 1))
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ft_left(tab, length, f) || ft_right(tab, length, f))
		return (1);
	return (0);
}
