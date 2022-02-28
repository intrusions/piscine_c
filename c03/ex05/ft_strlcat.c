/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:26:33 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/07 19:50:18 by jucheval         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				dest_size;
	int				src_size;

	i = ft_strlen(dest);
	j = 0;
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	while (src[j] && i < (size - 1) && size > 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size == 0)
		return (src_size);
	if (i < size)
		return (dest_size + src_size);
	else
		return (src_size + 1);
}
