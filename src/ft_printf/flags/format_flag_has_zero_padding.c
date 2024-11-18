/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_has_zero_padding.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:09 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:36 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format_flag_has_zero_padding(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__ZERO_PADDING) != 0);
}
