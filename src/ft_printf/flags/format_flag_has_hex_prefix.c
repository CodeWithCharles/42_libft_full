/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_has_hex_prefix.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:36:32 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:30 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format_flag_has_hex_prefix(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__HEX_PREFIX) != 0);
}
