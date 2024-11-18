/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_has_align_sign.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:34:10 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:28 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format_flag_has_align_sign(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__ALIGN_SIGN) != 0);
}
