/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:08:39 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/18 11:03:54 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	error_handler(char *str)
{
	printf("\033[31m%s\033[0m", str);
	exit(1);
}

int	not_number(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			if (!((tab[i][j] >= '0' && tab[i][j] <= '9') || tab[i][j] == '-'))
				return (1);
	}
	return (0);
}

int	check_number(char **av)
{
	if (ft_atol(av[1]) >= 10000 || ft_atol(av[1]) <= 0)
		return (1);
	if (ft_atol(av[2]) > INT_MAX || ft_atol(av[2]) <= 0)
		return (1);
	if (ft_atol(av[3]) > INT_MAX || ft_atol(av[3]) <= 0)
		return (1);
	if (ft_atol(av[4]) > INT_MAX || ft_atol(av[4]) <= 0)
		return (1);
	if (av[5] && (ft_atol(av[5]) > INT_MAX || ft_atol(av[5]) <= 0))
		return (1);
	return (0);
}

void	check_errors(int ac, char **av)
{
	if ((ac - 1) < 4 || (ac - 1) > 5)
		error_handler("Error : Number of Args Not Valid!!!\n");
	if (not_number(av) == 1)
		error_handler("Error : Arguments Not Numbers!!!\n");
	if (check_number(av) == 1)
		error_handler("Error : Size of An Arguments Not Valid !!!\n");
}
