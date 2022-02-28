/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:37:53 by jucheval          #+#    #+#             */
/*   Updated: 2022/02/22 09:15:57 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str);
void	ft_putstr(char *str);

int	ft_addition(char *a, char *b)
{
	return (ft_atoi(a) + ft_atoi(b));
}

int	ft_division(char *a, char *b)
{
	return (ft_atoi(a) / ft_atoi(b));
}

int	ft_soustraction(char *a, char *b)
{
	return (ft_atoi(a) - ft_atoi(b));
}

int	ft_modulo(char *a, char *b)
{
	return (ft_atoi(a) % ft_atoi(b));
}

int	ft_multiplication(char *a, char *b)
{
	return (ft_atoi(a) * ft_atoi(b));
}
