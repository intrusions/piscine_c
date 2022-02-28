/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_spe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:48:45 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/20 14:44:13 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_spe(char *str, unsigned int *nbr)
{
	unsigned int		i;
	long long			r;

	i = 0;
	r = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		r = r * 10 + (str[i] - '0');
		if (r > 4294967295)
			return (0);
		i++;
	}
	*nbr = r;
	if (str[i])
		return (0);
	return (1);
}
