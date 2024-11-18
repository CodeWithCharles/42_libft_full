/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_has_hex_prefix.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:36:32 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/06 15:14:56 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	format_flag_has_hex_prefix(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__HEX_PREFIX) != 0);
}
