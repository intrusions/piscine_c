/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:23:23 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/13 16:30:20 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_print_errors(void);
int		ft_resolve(int **tab, int index, int **input);
int		ft_convert_input(int **input, char *argv);
void	ft_print_tab(int **tab);
int		**ft_init(void);
int		ft_check_params(char argc, char **argv);
int		ft_free(int **tab);

int	main(int argc, char **argv)
{
	int		**tab;
	int		**input;

	if (argc == 2)
	{
		if (!(ft_check_params(argc, argv)))
			ft_print_errors();
		else
		{
			input = ft_init();
			tab = ft_init();
			ft_convert_input(input, argv[1]);
			if (ft_resolve(tab, 0, input))
				ft_print_tab(tab);
			else
				ft_print_errors();
			if (input)
				ft_free(input);
			if (tab)
				ft_free(tab);
		}
	}
	else
		ft_print_errors();
	return (0);
}
