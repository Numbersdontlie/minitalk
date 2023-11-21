/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:15:22 by lperez-h          #+#    #+#             */
/*   Updated: 2023/11/21 12:03:36 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "Printf/ft_printf.h"

void	send_signal(int pid, char *mensaje)
{
	static char	c;
	static char	b;
	int			bits;

	while (*mensaje)
	{
		c = *mensaje; 
		bits = 8;
		while (bits--)
		{
			//ft_printf("%c", c);
			b = (c >> bits & 1); // b = c >> bits;
			//ft_printf("%c", b);
			if (b == 1)
			{
				kill(pid, SIGUSR1);
				ft_printf("%i", 1);
			}
			else
			{
				kill(pid, SIGUSR2);
				ft_printf("%i", 0);
			}
			usleep(500);
		}
		//ft_printf("%c", b);
		mensaje++;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGINT || signum == SIGTERM)
		exit (0);
	/*if (signum == SIGUSR1 || signum == SIGUSR2)
		send_signal();
		//ft_printf("Signal is alive!\n");*/
}

void	config_signals(void)
{
	struct sigaction	sig;

	sig.sa_handler = &sig_handler;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		ft_printf("Failed to change SIGUSR1 behavior");
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		ft_printf("Failed to change SIGUSR2 behavior");
}

int	main(int argc, char **argv)
{
	int		id_server;
	char	*mensaje;

	if (argc == 3)
	{
		id_server = ft_atoi(argv[1]);
		if (!id_server)
		{
			ft_printf("[ERROR]. try different argument");
			return (0);
		}
		mensaje = argv[2];
		if (mensaje[0] == 0)
		{
			ft_printf("Bitte ein texte eingabe, danke");
			return (0);
		}
		config_signals();
		send_signal(id_server, mensaje);
	}
	else
		ft_printf("[ERROR]. Count your arguments. ;) XD");
	return (0);
}
