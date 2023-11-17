/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:01:00 by lperez-h          #+#    #+#             */
/*   Updated: 2023/11/17 10:46:29 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _GNU_SOURCE

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "Printf/ft_printf.h"

void	send_signal(int pid, char *mensaje);
void	sig_handler(int signum);
void	config_signals(void);
void	deal_with_sig(int signum, siginfo_t *info, void *ucontent);

#endif
