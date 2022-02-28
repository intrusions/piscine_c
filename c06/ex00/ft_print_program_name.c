/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:07:56 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/09 01:13:05 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 1)
	{
		while (argv[0][i])
		{
			ft_putchar(argv[0][i]);
			i++;
		}
	}
	return (0);
}
