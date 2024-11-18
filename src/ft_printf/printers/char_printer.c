/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:44:37 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:18 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	_char_printer(va_list *arg_list, t_format *fmt)
{
	int	len;

	if (fmt->width <= 0)
		fmt->width = 1;
	len = fmt->width--;
	if (format_flag_has_left_justify(fmt))
		ft_putchar_fd(va_arg(*arg_list, int), 1);
	while (fmt->width--)
		ft_putchar_fd(' ', 1);
	if (!format_flag_has_left_justify(fmt))
		ft_putchar_fd(va_arg(*arg_list, int), 1);
	return (len);
}
