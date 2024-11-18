/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:53:47 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:05 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	_string_printer(va_list *arg_list, t_format *fmt)
{
	char	*str;

	str = va_arg(*arg_list, char *);
	if (str)
		return (string_printer(fmt, str));
	if (!format_flag_has_precision(fmt)
		|| (unsigned long) fmt->precision + 1 >= sizeof(NULL_STRING))
		return (string_printer(fmt, (char *) NULL_STRING));
	return (string_printer(fmt, (char *) ""));
}
