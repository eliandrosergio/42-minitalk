/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:36:33 by efaustin          #+#    #+#             */
/*   Updated: 2024/08/28 15:36:34 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signal(int pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	int		pdiserver;
	char	*mensage;

	if (ac == 3)
	{
		pdiserver = ft_atoi(av[1]);
		mensage = av[2];
		send_signal(pdiserver, mensage);
		send_signal(pdiserver, "\n");
	}
	else
		ft_printf("parametros <%s> <PID_server> <mensagem>", av[0]);
	return (0);
}
