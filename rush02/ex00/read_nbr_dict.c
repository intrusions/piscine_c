/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_nbr_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:28:39 by afelten           #+#    #+#             */
/*   Updated: 2022/02/20 15:05:05 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		get_len_nbr(char *nbr);
char	*strcpy_nbr(char *dest, char *src);

void	initialize_str_big(char *str, int index)
{
	int	i;

	i = 0;
	if (index == 28)
	{
		str[0] = '1';
		str[1] = '0';
		str[2] = '0';
	}
	else
	{
		i = 0;
		str[0] = '1';
		while (i < (index - 28) * 3)
			str[++i] = '0';
	}
}

void	initialize_str(char *str, int index)
{
	int	i;

	i = 0;
	while (i < 38)
		str[i++] = 0;
	if (index < 10)
		str[0] = index + '0';
	else if (index < 21)
	{
		str[0] = index / 10 + '0';
		str[1] = index % 10 + '0';
	}
	else if (index < 28)
	{
		str[0] = index - 18 + '0';
		str[1] = '0';
	}
	else
		initialize_str_big(str, index);
}

int	strcmp_nbr(char *nbr1, char *nbr2)
{
	int	i;

	i = 0;
	if (*nbr2 == '0' && *(nbr2 + 1) != ':' && *(nbr2 + 1) != ' ')
	{
		while (*nbr2 == '0')
			nbr2++;
	}
	while (nbr1[i] && nbr2[i] != ' ' && nbr2[i] != ':' && nbr1[i] == nbr2[i])
		i++;
	if (!nbr1[i] && (nbr2[i] == ' ' || nbr2[i] == ':'))
		return (1);
	return (0);
}

void	get_nbr(char **dict, int index, char *line)
{
	int	i;
	int	len;

	i = 0;
	while (line[i] != ':')
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	len = get_len_nbr(line + i);
	dict[index] = malloc((len + 1) * sizeof(char));
	if (dict[index])
	{
		strcpy_nbr(dict[index], line + i);
		dict[index][len] = 0;
	}
}

void	fill_dict(char **dict, char *line)
{
	char	nbr[38];
	int		i;

	i = 0;
	while (i < 41)
	{
		initialize_str(nbr, i);
		if (strcmp_nbr(nbr, line))
		{
			get_nbr(dict, i, line);
			return ;
		}
		i++;
	}
}
