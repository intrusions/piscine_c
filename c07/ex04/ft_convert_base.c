/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:46:17 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/16 03:16:16 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_number(int nbr, char *base);
char	*ft_itoa_base(long long nb, char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long long	ft_convert(char *str, char *base)
{
	long long	i;
	long long	j;
	long long	r;

	i = 0;
	r = 0;
	while (str[i])
	{
		j = 0;
		while (base[j] && str[i] != base[j])
			j++;
		if (j == ft_strlen(base))
			break ;
		r = r * ft_strlen(base) + j;
		i++;
	}
	return (r);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == '-' || base[i] == '+' || base[i] == ' '
				|| base[i] == '\t' || base[i] == '\v'
				|| base[i] == '\n' || base[i] == '\r'
				|| base[i] == '\f')
				return (0);
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long long	ft_atoi_base(char *str, char *base)
{
	long long	neg;
	long long	i;

	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\n'
		|| str[i] == '\r'
		|| str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	return (ft_convert(str + i, base) * neg);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long		number_base10;
	char			*number_convert;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	number_base10 = ft_atoi_base(nbr, base_from);
	number_convert = ft_itoa_base(number_base10, base_to);
	return (number_convert);
}
