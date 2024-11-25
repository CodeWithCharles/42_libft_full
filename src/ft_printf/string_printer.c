/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:47:55 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/25 14:54:03 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// Declare static functions

static void	putnstr(const char *str, size_t len, const int fd);

// Main function

int	string_printer(t_format *fmt, char *str)
{
	size_t	s_len;
	size_t	len;

	s_len = ft_strlen(str);
	if (format_flag_has_precision(fmt))
		s_len = min(fmt->precision, s_len);
	fmt->width = max(0, fmt->width - s_len);
	len = s_len + fmt->width;
	if (format_flag_has_left_justify(fmt))
		putnstr(str, s_len, fmt->fd);
	ft_putnchr_fd(fmt->fd, ' ', fmt->width);
	if (!format_flag_has_left_justify(fmt))
		putnstr(str, s_len, fmt->fd);
	return (len);
}

// Static function implementations

static void	putnstr(const char *str, size_t len, const int fd)
{
	while (len--)
		ft_putchar_fd(*str++, fd);
}
