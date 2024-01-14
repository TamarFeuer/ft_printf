/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfeuer <tfeuer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:42:56 by tfeuer            #+#    #+#             */
/*   Updated: 2024/01/14 14:06:27 by tfeuer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

#define LOWER_CASE 1
#define UPPER_CASE 2

int	ft_printf(const char *format, ...);
int	sortnprint_arg(char c, va_list ptr);
int	print_char(char c);
int	print_str(char	*str);
int	print_num(int nb);
int	print_uns_num(unsigned int nb);
int	print_hex(unsigned int nb, int hex_case);
int	print_adr(unsigned long int nb);

#endif