/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:35:30 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/15 22:01:31 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	ft_count_number(long long nbr, char *base)
{
	int		count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		count++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		count++;
		nbr /= ft_strlen(base);
	}
	return (count);
}

char	*ft_itoa_base(long long nb, char *base)
{
	int				count;
	char			*converted;

	count = ft_count_number(nb, base);
	converted = malloc(sizeof(char) * (count + 1));
	if (!converted)
		return (0);
	if (nb == 0)
		converted[0] = base[0];
	if (nb < 0)
	{
		converted[0] = '-';
		nb *= -1;
	}
	converted[count--] = '\0';
	while (nb > 0)
	{
		converted[count] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		count--;
	}
	return (converted);
}
