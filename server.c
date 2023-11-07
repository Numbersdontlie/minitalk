/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:53:16 by lperez-h          #+#    #+#             */
/*   Updated: 2023/11/07 15:27:32 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "Printf/ft_printf.h"

void	deal_with_sig(int signum, siginfo_t *info, void *ucontent)
{
	static int				i;
	static unsigned char	c;

	(void)ucontent;
	i = -1;
	if(i < 0)
		i = 7;
	if (signum == SIGUSR1)
		c |= (1 << i);
	i--;
	if (i > 0)
	{
		printf("%c",c);
		fflush(0);
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf("Server failed to send SIGUSR1");
	}
}
/*
void	signals(void)
{

	sig.sa_sigaction = &deal_with_sig;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		ft_printf("Failed SIGUSR1 behavior");
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		ft_printf("Failed SIGUSR2 behavior");
}*/

int	main(void)
{
	struct sigaction	act;
	
	ft_printf("Welcome to the matrix, blue or red pill?\n");
	ft_printf("My server PID is: %d\n", getpid());
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = &deal_with_sig;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	
	// signals();
	while (1)
	{
		pause();
	}
	return (0);
}
