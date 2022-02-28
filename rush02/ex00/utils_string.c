/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:24:14 by afelten           #+#    #+#             */
/*   Updated: 2022/02/20 15:05:32 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int					i;
	unsigned int		j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*strcpy_nbr(char *dest, char *src)
{
	int	i;
	int	j;
	int	space;

	i = 0;
	j = 0;
	space = 0;
	while (src[i] != '\n')
	{
		if (src[i] != ' ')
			space = 0;
		if (space == 0)
		{
			dest[j] = src[i];
			j++;
		}
		if (src[i] == ' ')
			space = 1;
		i++;
	}
	return (dest);
}

int	get_len_nbr(char *nbr)
{
	int	len;
	int	i;
	int	space;

	len = 0;
	i = 0;
	space = 0;
	while (nbr[i] != '\n')
	{
		if (nbr[i] != ' ')
			space = 0;
		if (space == 0)
			len++;
		if (nbr[i] == ' ')
			space = 1;
		i++;
	}
	return (len);
}
