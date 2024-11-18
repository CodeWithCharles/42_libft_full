/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_has_precision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:02 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/06 15:39:23 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	format_flag_has_precision(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__PRECISION) != 0);
}
