/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:06:04 by cpoulain          #+#    #+#             */
/*   Updated: 2024/12/20 09:50:56 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	double	value;
	char	*str;

	value = 5478.12455676321;
	str = ft_dtoa(value, 12);
	ft_printf("%s\n", str);
	return (0);
}
