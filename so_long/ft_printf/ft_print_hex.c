/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:59:39 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/01 09:59:40 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long int n, char uplow)
{
	unsigned int	first;
	unsigned int	sec;
	char			d;

	first = n % 16;
	sec = n / 16;
	if (first >= 10)
		d = (first - 10) + uplow;
	else
		d = first + '0';
	if (sec == 0)
	{
		return (ft_putchar_fd(d, 1));
	}
	if (sec < 16)
	{
		if (sec >= 10)
			return (ft_putchar_fd(sec - 10 + uplow, 1) + ft_putchar_fd(d, 1));
		return (ft_putchar_fd(sec + '0', 1) + ft_putchar_fd(d, 1));
	}
	return (ft_print_hex(sec, uplow) + ft_putchar_fd(d, 1));
}
