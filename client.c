/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:50:38 by mbouayou          #+#    #+#             */
/*   Updated: 2023/01/25 12:33:48 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int pid, char i)
{
	int	error;
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if ((i & (0x01 << bit)))
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		usleep(300);
		if (error == -1)
		{
			ft_putstr("INVALID PID");
			exit(EXIT_FAILURE);
		}
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_putstr("PID SHOULD BE GREATER OR EQUAL THAN 1");
			exit(EXIT_FAILURE);
		}
		while (av[2][i])
		{
			ft_signal(pid, av[2][i]);
			i++;
		}
	}
	else
	{
		ft_putstr("PASSING ARGUMENTS NOT CORRECT");
		exit(EXIT_FAILURE);
	}
	return (0);
}
