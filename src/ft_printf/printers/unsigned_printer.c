/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:43:13 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/07 17:44:19 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_unsigned_printer(va_list *arg_list, t_format *fmt)
{
	unsigned int	x;

	x = va_arg(*arg_list, unsigned int);
	fmt->flags &= ~(FMT_FLAG__ALIGN_SIGN | FMT_FLAG__FORCE_SIGN);
	return (number_printer(fmt, (long) x));
}
