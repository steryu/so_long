/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:59:38 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/01 09:59:39 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_for_p(unsigned long n, char *uplow)
{
	if (n != 0)
	{
		ft_print_hex_for_p(n / 16, uplow);
		ft_putchar_fd(uplow[n % 16], 1);
	}
}

int	ft_convert(unsigned long n, char uplow)
{
	int			i;
	char		*low;
	char		*up;

	low = "0123456789abcdef";
	up = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
	{
		ft_putchar_fd(low[n], 1);
		return (1);
	}
	if (uplow == 'a')
		ft_print_hex_for_p(n, low);
	if (uplow == 'A')
		ft_print_hex_for_p(n, up);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_print_point(unsigned long n)
{
	int		len;

	len = 0;
	ft_print_string("0x");
	len = ft_convert(n, 'a');
	return (len + 2);
}
