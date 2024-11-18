/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag_has_force_sign.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:33:20 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:29 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format_flag_has_force_sign(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__FORCE_SIGN) != 0);
}
