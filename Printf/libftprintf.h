/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:05:09 by lperez-h          #+#    #+#             */
/*   Updated: 2023/07/23 23:13:51 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include	<unistd.h>
# include	<stdarg.h>
# include	<stdlib.h>
# include	<limits.h>

int			ft_printf(const char *format, ...);
int			ft_formatos(const char format, va_list args);
int			ft_print_hexa(unsigned int num, const char format);
int			ft_print_ptr(unsigned long long ptr);
int			ft_print_unsigned(unsigned int n);
int			ft_putchar(char c);
int			ft_printstr(char *str);
int			ft_printnbr(int n);
int			ft_hex_len(unsigned int n);
void		ft_put_hex(unsigned int num, const char format);
int			ft_ptr_len(unsigned int num);
void		ft_put_ptr(unsigned int num);
int			ft_putchar_fd(char c, int fd);
int			ft_size(int n);
char		*ft_itoa(int n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strchr(const char *s, int c);

#endif