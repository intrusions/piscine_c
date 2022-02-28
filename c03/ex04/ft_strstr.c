/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:29:16 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/11 10:15:50 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int			n;
	int			k;
	char		*ptr;

	ptr = 0;
	n = 0;
	k = 0;
	if (to_find[k] == '\0')
		return (str);
	while (str[n] != '\0')
	{
		k = 0;
		if (str[n] == to_find[k])
		{
			while (to_find[k] && (str[n + k] == to_find[k]))
			{
				if (to_find[k + 1] == '\0')
					return (&str[n]);
				k++;
			}
		}
		n++;
	}
	return (ptr);
}
