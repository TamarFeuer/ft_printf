/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfeuer <tfeuer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:42:23 by tfeuer            #+#    #+#             */
/*   Updated: 2024/01/14 14:02:35 by tfeuer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	sortnprint_arg(char c, va_list ptr)
{
	unsigned long int	address;

	if (c == 'c')
		return (print_char(va_arg(ptr, int)));
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'd' || c == 'i')
		return (print_num(va_arg(ptr, int)));
	if (c == 'u')
		return (print_uns_num(va_arg(ptr, unsigned int)));
	if (c == 'x')
		return (print_hex(va_arg(ptr, unsigned int), LOWER_CASE));
	if (c == 'X')
		return (print_hex(va_arg(ptr, unsigned int), UPPER_CASE));
	if (c == 'p')
	{
		address = va_arg (ptr, unsigned long int);
		if (!address)
			return (write (1, "(nil)", 5));
		write(1, "0x", 2);
		return (print_adr(address) + 2);
	}
	if (c == 's')
		return (print_str(va_arg(ptr, char *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ptr;

	len = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (-1);
			len += sortnprint_arg(format[i + 1], ptr);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}
