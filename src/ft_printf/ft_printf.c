/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:31:14 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/25 15:39:01 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format_in, ...)
{
	va_list	args;
	int		written;

	va_start(args, format_in);
	written = ft_printf_base(0, format_in, &args);
	va_end(args);
	return (written);
}

int	fd_printf(int fd, const char *format_in, ...)
{
	va_list	args;
	int		written;

	va_start(args, format_in);
	if (!fd)
		fd = 1;
	written = ft_printf_base(fd, format_in, &args);
	va_end(args);
	return (written);
}
