/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:53:16 by lperez-h          #+#    #+#             */
/*   Updated: 2023/10/09 00:09:58 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "Printf/ft_printf.h"

void	deal_with_bit(int bit)
{
	int	caracter;
	int	i;

	i = 0;
	caracter = 0;
	caracter += ((bit & 1) << i);
	i++;
	if (i == 7)
	{
		ft_printf("%c", caracter);
		if (!caracter)
			ft_printf("\n");
		caracter = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome to the matrix, blue or red pill?\n");
	ft_printf("My server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, deal_with_bit);
		signal(SIGUSR1, deal_with_bit);
		pause();
	}
	return (0);
}
