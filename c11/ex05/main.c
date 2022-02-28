/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:32:36 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/22 09:15:39 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_addition(char *a, char *b);
int		ft_division(char *a, char *b);
int		ft_soustraction(char *a, char *b);
int		ft_modulo(char *a, char *b);
int		ft_multiplication(char *a, char *b);
void	ft_putchar(char c);
void	ft_putstr(char *str);

void	ft_putnbr(int nb)
{
	long long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

void	ft_traitement(char **argv, int (*tab[5])(char *, char *))
{
	if (argv[2][0] == '+')
		ft_putnbr((*tab[0])(argv[1], argv[3]));
	else if (argv[2][0] == '-')
		ft_putnbr((*tab[2])(argv[1], argv[3]));
	else if (argv[2][0] == '/')
	{
		if (argv[3][0] == '0')
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr((*tab[1])(argv[1], argv[3]));
	}
	else if (argv[2][0] == '%')
	{
		if (argv[3][0] == '0')
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr((*tab[3])(argv[1], argv[3]));
	}
	else if (argv[2][0] == '*')
		ft_putnbr((*tab[4])(argv[1], argv[3]));
	else
		ft_putchar('0');
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	(*tab[5])(char *, char *);

	tab[0] = ft_addition;
	tab[1] = ft_division;
	tab[2] = ft_soustraction;
	tab[3] = ft_modulo;
	tab[4] = ft_multiplication;
	if (argc == 4)
		ft_traitement(argv, tab);
}
