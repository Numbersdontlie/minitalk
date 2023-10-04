/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperez-h <lperez-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:42:35 by lperez-h          #+#    #+#             */
/*   Updated: 2023/10/05 00:49:49 by lperez-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	while (((*str >= 9) && (*str <= 13)) || (*str == 32))
		str++;
	if ((*str == 43) || (*str == 45))
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	result = 0;
	while (((*str >= 48) && (*str <= 57)))
	{
		result = ((result * 10) + (*str - 48));
		str++;
	}
	return (result * sign);
}
