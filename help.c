/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:56:00 by mbouayou          #+#    #+#             */
/*   Updated: 2023/01/25 12:29:24 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_atoi(const char *str)
{
	unsigned long long	r;
	int					sign;

	sign = 1;
	r = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
	if (*str == '-')
	{
		sign = sign * (-1);
		str++;
	}
	else if (*str == '+')
			str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - '0';
		if (r > __LONG_MAX__ && sign == 1)
			return (-1);
		if (r > __LONG_MAX__ && sign == -1)
			return (0);
		str++;
	}
	return (r * sign);
}
