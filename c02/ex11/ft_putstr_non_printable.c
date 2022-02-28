/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:53:06 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/08 21:34:03 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(char c)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(base[(unsigned char)c / 16]);
	ft_putchar(base[(unsigned char)c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] > 31 && str[i] < 127)
			ft_putchar(str[i]);
		else
			ft_print_hex(str[i]);
		i++;
	}
}
