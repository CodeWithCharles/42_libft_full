/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_has_align_sign.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:34:10 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/06 15:14:56 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	format_flag_has_align_sign(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__ALIGN_SIGN) != 0);
}
