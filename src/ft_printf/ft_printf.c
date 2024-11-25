/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:55:25 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/25 14:52:47 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// Declare static functions

static void	init_printers(
				t_spec_printer *printers);
static int	handle(
				int fd,
				const char **fmt_in_ptr,
				va_list *list,
				t_spec_printer *printers);
static void	read_number(
				const char **str,
				int *value_ptr);
static int	read_format(
				t_format *fmt,
				const char **fmt_in_ptr);
// Main function

int	ft_printf(int fd, const char *format_in, ...)
{
	va_list			args;
	int				printed_char;
	t_spec_printer	printers[8];

	if (!fd)
		fd = 1;
	printed_char = 0;
	va_start(args, format_in);
	init_printers(printers);
	while (*format_in)
	{
		if (*format_in++ != '%')
		{
			++printed_char;
			ft_putchar_fd(format_in[-1], fd);
			continue ;
		}
		printed_char += handle(fd, &format_in, &args, printers);
	}
	va_end(args);
	return (printed_char);
}

// Static implementations

static void	init_printers(t_spec_printer *printers)
{
	printers[0] = _char_printer;
	printers[1] = _string_printer;
	printers[2] = _pointer_printer;
	printers[3] = _decimal_printer;
	printers[4] = _integer_printer;
	printers[5] = _unsigned_printer;
	printers[6] = _lo_hex_printer;
	printers[7] = _up_hex_printer;
}

static int	handle(
	int fd,
	const char **fmt_in_ptr,
	va_list *list,
	t_spec_printer *printers)
{
	t_format		format;
	t_spec_printer	printer;
	int				len;
	const char		*start;

	format.fd = fd;
	if (read_format(&format, fmt_in_ptr))
	{
		start = *fmt_in_ptr;
		while (*start != '%')
			--start;
		len = *fmt_in_ptr - start;
		while (start < *fmt_in_ptr)
			ft_putchar_fd(*start++, fd);
		return (len);
	}
	if (format.specifier == '%')
	{
		ft_putchar_fd('%', fd);
		return (1);
	}
	printer = printers[
		ft_strchr(FMT_SPECIFIERS, format.specifier) - FMT_SPECIFIERS];
	return (printer(list, &format));
}

static void	read_number(
	const char **str,
	int *value_ptr)
{
	int	x;

	x = 0;
	while (**str && ft_isdigit(**str))
	{
		x = 10 * x + **str - '0';
		++(*str);
	}
	*value_ptr = x;
}

static int	read_format(
	t_format *fmt,
	const char **fmt_in_ptr)
{
	char	*x;

	ft_bzero(fmt, sizeof(t_format));
	x = ft_strchr(FMT_FLAGS, *(*fmt_in_ptr));
	while (x)
	{
		++(*fmt_in_ptr);
		*((char *)&fmt->flags) |= 1 << (x - FMT_FLAGS);
		x = ft_strchr(FMT_FLAGS, *(*fmt_in_ptr));
	}
	read_number(fmt_in_ptr, &fmt->width);
	if (**fmt_in_ptr && **fmt_in_ptr == '.')
	{
		++(*fmt_in_ptr);
		read_number(fmt_in_ptr, &fmt->precision);
		fmt->flags |= FMT_FLAG__PRECISION;
	}
	x = ft_strchr(FMT_SPECIFIERS, **fmt_in_ptr);
	if (!*(*fmt_in_ptr)++ || !x)
		return (1);
	fmt->specifier = *x;
	return (0);
}
