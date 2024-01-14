/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfeuer <tfeuer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:42:31 by tfeuer            #+#    #+#             */
/*   Updated: 2024/01/14 14:02:47 by tfeuer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	print_num(int nb)
{
	long	n;
	int		len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += print_num(n / 10);
		n %= 10;
	}
	if (n < 10)
		len += print_char(n + '0');
	return (len);
}

int	print_uns_num(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += print_uns_num(nb / 10);
		nb %= 10;
	}
	if (nb < 10)
		len += print_char(nb + '0');
	return (len);
}

int	print_hex(unsigned int nb, int hex_case)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_hex(nb / 16, hex_case);
		nb %= 16;
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + '0');
		else
		{
			if (hex_case == LOWER_CASE)
				len += print_char(nb - 10 + 'a');
			else
				len += print_char(nb - 10 + 'A');
		}
	}
	return (len);
}

int	print_adr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_adr(nb / 16);
		nb %= 16;
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + '0');
		else
			len += print_char(nb - 10 + 'a');
	}
	return (len);
}
