/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:48:04 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/19 16:22:11 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_word(char *str, char *charset)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	if (str[i] == 0)
		return (0);
	while (str[i])
	{
		while (ft_is_charset(str[i], charset) && str[i])
			i++;
		if (!ft_is_charset(str[i], charset) && str[i])
		{
			while (!ft_is_charset(str[i], charset) && str[i])
				i++;
			word++;
		}
	}
	return (word);
}

char	**ft_malloc_word(char *str, char *charset, char **dest, int word)
{
	int		i;
	int		j;
	int		letter;

	i = 0;
	j = 0;
	while (str[i])
	{
		letter = 0;
		while (ft_is_charset(str[i], charset) && str[i])
			i++;
		if (!ft_is_charset(str[i], charset) && str[i])
		{
			while (!ft_is_charset(str[i], charset) && str[i])
			{
				letter++;
				i++;
			}
		}
		if (j < word)
			dest[j++] = malloc((sizeof(char) * letter) + 1);
	}
	return (dest);
}

char	**ft_put_word(char *str, char *charset, char **dest)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (ft_is_charset(str[i], charset) && str[i])
			i++;
		if (!ft_is_charset(str[i], charset) && str[i])
		{
			while (!ft_is_charset(str[i], charset) && str[i])
				dest[k][j++] = str[i++];
			dest[k][j] = '\0';
			k++;
		}
	}
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		word;

	word = ft_is_word(str, charset);
	dest = malloc(sizeof(char *) * (word + 1));
	if (!dest)
		return (0);
	dest = ft_malloc_word(str, charset, dest, word);
	dest = ft_put_word(str, charset, dest);
	dest[word] = 0;
	return (dest);
}
