/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:57:04 by cpoulain          #+#    #+#             */
/*   Updated: 2024/12/20 09:49:36 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Static declaration

static char	*frac_to_str(
				double value,
				int precision
				);

// dtoa implementation

char	*ft_dtoa(
	double value,
	int precision
)
{
	long long	int_part;
	double		frac_part;
	char		*int_str;
	char		*frac_str;

	int_part = (long long)value;
	frac_part = value - int_part;
	if (precision <= 0)
		return (ft_itoa((int)int_part));
	if (frac_part < 0)
		frac_part = -frac_part;
	int_str = ft_itoa((int)int_part);
	if (int_str == NULL)
		return (NULL);
	frac_str = frac_to_str(frac_part, precision);
	if (frac_str == NULL)
		return (free(int_str), NULL);
	ft_strcat(&int_str, frac_str);
	free(frac_str);
	return (int_str);
}

// Static implementation

char	*frac_to_str(
	double value,
	int precision
)
{
	char	*result;
	int		i;
	int		digit;

	if (value < 0)
		value = -value;
	result = malloc(sizeof(char) * (precision + 2));
	if (result == NULL)
		return (NULL);
	result[0] = '.';
	i = 1;
	while (i <= precision)
	{
		value *= 10;
		digit = (int)value;
		result[i] = digit + '0';
		value -= digit;
		i++;
	}
	result[precision + 1] = '\0';
	return (result);
}
