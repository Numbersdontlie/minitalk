/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 23:42:53 by lperez-h          #+#    #+#             */
/*   Updated: 2023/07/30 02:37:45 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(size_t ptr, int *length)
{
	char	str[25];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	*length += 2;
	if (ptr == 0)
	{
		ft_putchar('0', length);
		return ;
	}
	while (ptr != 0)
	{
		str[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar(str[i], length);
	}
}
