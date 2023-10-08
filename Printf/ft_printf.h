/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:05:09 by lperez-h          #+#    #+#             */
/*   Updated: 2023/10/09 00:09:10 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

int			ft_printf(const char *string, ...);
void		ft_putchar(char c, int *length);
void		ft_printstr(char *str, int *length);
void		ft_printnbr(int n, int *lenght);
void		ft_print_hex(unsigned int n, int *lenght, char x_or_x);
void		ft_print_ptr(size_t ptr, int *lenght);
void		ft_print_unsigned(unsigned int n, int *length);
int			ft_strlen(const char *str);
int			ft_atoi(const char *str);

#endif