/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:44:56 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/14 22:29:01 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*dest;
	int		i;
	int		*ptr;

	i = 0;
	ptr = 0;
	if (min >= max)
		return (ptr);
	dest = malloc(sizeof(int) * (max - min));
	if (!dest)
		return (0);
	while (min < max)
	{
		dest[i] = min;
		i++;
		min++;
	}
	return (dest);
}
