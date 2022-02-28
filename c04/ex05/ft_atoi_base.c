/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:13:47 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/24 12:21:25 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int	ft_convert(char *str, char *base)
{
	int	i;
	int	j;
	int	r;

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

int	ft_atoi_base(char *str, char *base)
{
	int	neg;
	int	i;

	i = 0;
	neg = 1;
	if (!ft_check_base(base))
		return (0);
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