/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:23:52 by lperez-h          #+#    #+#             */
/*   Updated: 2023/07/30 02:46:09 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_formatos(char s, va_list *args, int *len)
{
	if (s == '%')
		ft_putchar('%', len);
	else if (s == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (s == 's')
		ft_printstr(va_arg(*args, char *), len);
	else if (s == 'p')
		ft_print_ptr(va_arg(*args, size_t), len);
	else if (s == 'd' || s == 'i')
		ft_printnbr(va_arg(*args, int), len);
	else if (s == 'u')
		ft_print_unsigned(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_print_hex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_print_hex(va_arg(*args, unsigned int), len, 'X');
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_formatos(string[i], &args, &length);
			i++;
		}
		else
		{
			ft_putchar((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
