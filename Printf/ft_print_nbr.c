/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:40:10 by lperez-h          #+#    #+#             */
/*   Updated: 2023/07/30 02:37:11 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr(int n, int *length)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', length);
		ft_printnbr(n * -1, length);
	}
	else
	{
		if (n > 9)
			ft_printnbr(n / 10, length);
		ft_putchar(n % 10 + '0', length);
	}
}
