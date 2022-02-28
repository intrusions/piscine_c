/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 05:39:59 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/15 19:43:16 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_concat(char *dest, char **strs, char *sep, int size)
{
	int		i;
	int		j;
	int		k;
	int		n;

	i = 0;
	k = 0;
	while (i < size)
	{
		n = 0;
		j = 0;
		while (strs[i][j])
			dest[k++] = strs[i][j++];
		while (sep[n] && (i < (size - 1)))
			dest[k++] = sep[n++];
		i++;
	}
	dest[k] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*dest;
	int		str_len;

	i = 0;
	str_len = 0;
	while (i < size)
	{
		str_len += ft_strlen(strs[i]);
		i++;
	}
	str_len += (ft_strlen(sep) * (size - 1));
	if (size < 1)
		str_len = 1;
	dest = malloc(sizeof(char) * (str_len + 1));
	if (!dest)
		return (0);
	return (ft_concat(dest, strs, sep, size));
}