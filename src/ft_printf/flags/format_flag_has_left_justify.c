/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_has_left_justify.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:27:46 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/06 15:14:56 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	format_flag_has_left_justify(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__LEFT_JUSTIFY) != 0);
}
