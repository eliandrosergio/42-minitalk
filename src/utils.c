/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:36:37 by efaustin          #+#    #+#             */
/*   Updated: 2024/08/28 15:36:38 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putchar_pf(char c, int *num_caract)
{
	write(1, &c, 1);
	(*num_caract)++;
}

void	ft_putstr_pf(char *str, int *num_caract)
{
	if (str == NULL)
		ft_putstr_pf("(null)", num_caract);
	else
	{
		while (*str)
		{
			ft_putchar_pf(*str, num_caract);
			str++;
		}
	}
}

void	ft_putnbr(int number, int *num_caract)
{
	if (number == -2147483648)
		ft_putstr_pf("-2147483648", num_caract);
	else if (number < 0)
	{
		ft_putchar_pf('-', num_caract);
		number = -number;
		ft_putnbr(number, num_caract);
	}
	else if (number > 9)
	{
		ft_putnbr((number / 10), num_caract);
		ft_putchar_pf((number % 10) + 48, num_caract);
	}
	else
		ft_putchar_pf(number + 48, num_caract);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
