/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:00:22 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/22 03:08:35 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*dest;

	i = -1;
	dest = malloc(sizeof(int) * length);
	while (++i < length)
		dest[i] = f(tab[i]);
	return (dest);
}
