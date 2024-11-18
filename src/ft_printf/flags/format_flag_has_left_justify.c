/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_has_left_justify.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:27:46 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:32 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format_flag_has_left_justify(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__LEFT_JUSTIFY) != 0);
}
