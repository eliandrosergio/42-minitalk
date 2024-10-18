/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:36:21 by efaustin          #+#    #+#             */
/*   Updated: 2024/08/28 15:36:23 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_signal(int signal)
{
	static int	count_bit = 0;
	static char	character = 0;

	if (signal == SIGUSR1)
		character |= (1 << (7 - count_bit));
	count_bit++;
	if (count_bit == 8)
	{
		write (1, &character, 1);
		count_bit = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID do servidor: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
	}
}
