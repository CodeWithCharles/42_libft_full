/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_has_zero_padding.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:09 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/06 15:14:56 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	format_flag_has_zero_padding(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__ZERO_PADDING) != 0);
}
