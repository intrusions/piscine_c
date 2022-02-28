/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:27:00 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/08 16:34:27 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	while (n1 <= 98)
	{
		n2 = n1 + 1;
		while (n2 <= 99)
		{
			ft_putchar(n1 / 10 + '0');
			ft_putchar(n1 % 10 + '0');
			ft_putchar(' ');
			ft_putchar(n2 / 10 + '0');
			ft_putchar(n2 % 10 + '0');
			if (!(n2 == 99 && n1 == 98))
				write(1, &", ", 2);
			n2++;
		}
		n1++;
	}
}
