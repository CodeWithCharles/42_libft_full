/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:56:30 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:07 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	_pointer_printer(va_list *arg_list, t_format *fmt)
{
	void	*ptr;
	size_t	n;

	ptr = va_arg(*arg_list, void *);
	n = *(long *)&ptr;
	if (!n)
		return (string_printer(fmt, "(nil)"));
	fmt->flags |= FMT_FLAG__HEX_PREFIX;
	return (hex_printer(fmt, n, 0));
}
