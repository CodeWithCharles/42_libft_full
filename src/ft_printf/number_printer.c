/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:23:18 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/25 14:48:56 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// Declare static functions

static int	len_n(long n);
static void	print_number(unsigned long n, const int fd);
static void	print(t_format *fmt, long n, int pn);

// Main function

int	number_printer(t_format *fmt, long n)
{
	int	number_size;

	if (format_flag_has_precision(fmt) && fmt->precision == 0 && n == 0)
		number_size = 0;
	else
		number_size = len_n(n);
	fmt->precision -= number_size;
	if (n < 0 || format_flag_has_align_sign(fmt)
		|| format_flag_has_force_sign(fmt))
		++number_size;
	if (format_flag_has_zero_padding(fmt)
		&& !format_flag_has_left_justify(fmt)
		&& !format_flag_has_precision(fmt))
		fmt->precision = fmt->width - number_size;
	fmt->precision = max(0, fmt->precision);
	fmt->width = max(0, fmt->width - number_size - fmt->precision);
	print(fmt, n, number_size != 0);
	return (number_size + fmt->width + fmt->precision);
}

// Static function implementations

static int	len_n(long n)
{
	int	len;

	len = 1;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		++len;
		n /= 10;
	}
	return (len);
}

static void	print_number(unsigned long n, const int fd)
{
	if (n > 9)
		print_number(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

static void	print(t_format *fmt, long n, int pn)
{
	if (!format_flag_has_left_justify(fmt))
		ft_putnchr_fd(fmt->fd, ' ', fmt->width);
	if (!format_flag_has_force_sign(fmt)
		&& format_flag_has_align_sign(fmt) && n >= 0)
		ft_putchar_fd(' ', fmt->fd);
	if (format_flag_has_force_sign(fmt) && n >= 0)
		ft_putchar_fd('+', fmt->fd);
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fmt->fd);
	}
	ft_putnchr_fd(fmt->fd, '0', fmt->precision);
	if (pn)
		print_number((unsigned long) n);
	if (format_flag_has_left_justify(fmt))
		ft_putnchr_fd(fmt->fd, ' ', fmt->width);
}
