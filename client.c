/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:15:22 by lperez-h          #+#    #+#             */
/*   Updated: 2023/10/08 22:51:33 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "Printf/ft_printf.h"

void	send_signal(int pid, char *mensaje, size_t len)
{
	int		letra;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		letra = 0;
		while (letra < 7)
		{
			if (((unsigned char)(mensaje[i] >> letra) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			letra++;
			usleep(60);
		}
		i++;
	}
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
		send_signal(id_server, mensaje, ft_strlen(mensaje));
	}
	else
		ft_printf("[ERROR]. Count your arguments. ;) XD");
	return (0);
}
