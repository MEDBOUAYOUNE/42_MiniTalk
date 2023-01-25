/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:50:10 by mbouayou          #+#    #+#             */
/*   Updated: 2023/01/25 12:27:02 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_catch(int sig)
{
	static char	i;
	static int	bit;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Server PID ------>:  ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, ft_catch);
	signal(SIGUSR2, ft_catch);
	while (1)
	{
		pause();
	}
}
