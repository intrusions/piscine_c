/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:35:14 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/22 00:43:57 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char*))
{
	int		i;
	int		j;
	char	*tmp;

	if (tab[0])
		if (!tab[1])
			return ;
	i = 0;
	while (tab[i])
	{
		j = 1;
		while (tab[j])
		{
			if ((*cmp)(tab[j - 1], tab[j]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
