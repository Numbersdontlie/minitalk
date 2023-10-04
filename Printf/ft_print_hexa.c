/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:01:35 by lperez-h          #+#    #+#             */
/*   Updated: 2023/07/30 02:28:18 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int n, int *length, char x_or_x)
{
	char	str[25];
	char	*base;
	int		i;

	if (x_or_x == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (n == 0)
	{
		ft_putchar('0', length);
		return ;
	}
	while (n != 0)
	{
		str[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], length);
}
