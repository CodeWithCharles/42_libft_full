/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:34:58 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/25 14:53:26 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// Declare static functions

static int	len_hex(size_t n);
static void	print_hex(const char *charset, size_t n, const int fd);
static void	print(t_format *fmt, size_t n, int pn, int is_up);

// Main function

int	hex_printer(t_format *fmt, size_t n, int is_up)
{
	int	number_size;
	int	prefix;

	if (format_flag_has_precision(fmt) && fmt->precision == 0 && n == 0)
		number_size = 0;
	else
		number_size = len_hex(n);
	fmt->precision -= number_size;
	if (n == 0)
		fmt->flags &= ~FMT_FLAG__HEX_PREFIX;
	prefix = 2 * format_flag_has_hex_prefix(fmt);
	if (prefix)
		fmt->width -= 2;
	if (format_flag_has_zero_padding(fmt)
		&& !format_flag_has_left_justify(fmt)
		&& !format_flag_has_precision(fmt))
		fmt->precision = fmt->width - number_size;
	fmt->precision = max(0, fmt->precision);
	fmt->width = max(0, fmt->width - number_size - fmt->precision);
	print(fmt, n, number_size != 0, is_up);
	return (prefix + number_size + fmt->width + fmt->precision);
}

// Implement static functions

// Get length of n in hexadecimal

static int	len_hex(size_t n)
{
	int	len;

	len = 1;
	while (n > 0xf)
	{
		++len;
		n >>= 4;
	}
	return (len);
}

// Print n in hexadecimal

static void	print_hex(const char *charset, size_t n, const int fd)
{
	if (n > 0xf)
		print_hex(charset, n >> 4, fd);
	ft_putchar_fd(charset[n & 0xf], fd);
}

static void	print(t_format *fmt, size_t n, int pn, int is_up)
{
	char	*charset;

	charset = L_HEX_CHARSET;
	if (is_up)
		charset = U_HEX_CHARSET;
	if (!format_flag_has_left_justify(fmt))
		ft_putnchr_fd(fmt->fd, ' ', fmt->width);
	if (format_flag_has_hex_prefix(fmt)
		&& (!format_flag_has_precision(fmt) || fmt ->precision >= 0 || n))
		ft_putstr_fd(&charset[sizeof(L_HEX_CHARSET) - 3], fmt->fd);
	ft_putnchr_fd(fmt->fd, '0', fmt->precision);
	if (pn)
		print_hex(charset, n, fmt->fd);
	if (format_flag_has_left_justify(fmt))
		ft_putnchr_fd(fmt->fd, ' ', fmt->width);
}
