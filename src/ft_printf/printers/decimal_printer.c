/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:35:08 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:15 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	_decimal_printer(va_list *arg_list, t_format *fmt)
{
	int	x;

	x = va_arg(*arg_list, int);
	return (number_printer(fmt, (long) x));
}
