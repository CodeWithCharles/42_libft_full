/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:36:26 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/07 17:37:20 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_integer_printer(va_list *arg_list, t_format *fmt)
{
	int	x;

	x = va_arg(*arg_list, int);
	return (number_printer(fmt, (long) x));
}
