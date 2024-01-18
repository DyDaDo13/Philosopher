/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:01:30 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/17 09:08:09 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	ft_atol(const char *nptr)
{
	char	*str;
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	str = (char *)nptr;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	return (nb);
}

// static int	get_nb_of_digits(long int n)
// {
// 	int	nb;

// 	nb = 0;
// 	if (n == -2147483648)
// 		return (11);
// 	if (n < 0)
// 	{
// 		nb++;
// 		n *= -1;
// 	}
// 	while (n >= 10)
// 	{
// 		nb++;
// 		n = n / 10;
// 	}
// 	if (n < 10 || n == 0)
// 		nb++;
// 	return (nb);
// }

// static char	*fill_str(char *str, long int n, int nb_dg)
// {
// 	str[nb_dg] = '\0';
// 	if (n < 0)
// 	{
// 		str[0] = '-';
// 		n *= -1;
// 	}
// 	if (n == 0)
// 	{
// 		str[0] = '0';
// 		return (str);
// 	}
// 	while (nb_dg > 0 && n != 0)
// 	{
// 		str[nb_dg - 1] = ((n % 10) + '0');
// 		n /= 10;
// 		nb_dg--;
// 	}
// 	return (str);
// }

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	int		nb_dg;

// 	nb_dg = get_nb_of_digits((long int)n);
// 	str = malloc(sizeof(char) * nb_dg + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	str = fill_str(str, (long int)n, nb_dg);
// 	return (str);
// }