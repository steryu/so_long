/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:59:34 by svan-ass          #+#    #+#             */
/*   Updated: 2022/03/01 09:59:35 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_what_is_it(va_list arg, const char *format)
{
	int	len;

	len = 0;
	if (*format == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	if (*format == 's')
		return (ft_print_string(va_arg(arg, char *)));
	if (*format == 'p')
		return (ft_print_point(va_arg(arg, unsigned long)));
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	if (*format == 'u')
		return (ft_putnbr_un(va_arg(arg, unsigned int)));
	if (*format == 'x')
		return (ft_convert(va_arg(arg, unsigned int), 'a'));
	if (*format == 'X')
		return (ft_convert(va_arg(arg, unsigned int), 'A'));
	if (*format == '%')
		return (ft_putchar_fd('%', 1));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '\0')
			return (0);
		if (format[i] == '%')
		{
			len = len + ft_what_is_it(arg, &format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
