/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:53:16 by lperez-h          #+#    #+#             */
/*   Updated: 2023/11/21 12:03:14 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "Printf/ft_printf.h"

void	deal_with_sig(int signum, siginfo_t *info, void *ucontent)
{
	
	static char	c;
	static int	i;
	(void)ucontent;
	(void)info;
	
	if (signum == SIGUSR1)
	{
		c = (c << 1 | 1);
		i++;
	}
	if (signum == SIGUSR2)
	{
		c = c << 1;
		i++;
	}
	if ((i % 8) == 0)
	{
		write(1, &c, 1);
	}
}

int	main(void)
{
	struct sigaction	act;
	
	ft_printf("Welcome to the matrix, blue or red pill?\n");
	ft_printf("My server PID is: %d\n", getpid());
	//sigemptyset(&act.sa_mask);
	act.sa_sigaction = &deal_with_sig;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	
	//signals();
	while (1)
	{
		pause();
	}
	return (0);
}
