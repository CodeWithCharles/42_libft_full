/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:05:30 by cpoulain          #+#    #+#             */
/*   Updated: 2024/12/06 17:12:25 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Static declaration

static int	base_digit(char c, int base);

// Main function

int	ft_atoi_base(const char *str, int base)
{
	size_t		i;
	int			sign;
	long int	sum;

	if (!str)
		return (0);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	sum = 0;
	while (base_digit(str[i], base) != -1)
	{
		sum = sum * base + base_digit(str[i++], base);
		if (sum < 0)
			return ((sign != -1) * -1);
	}
	return (sum * sign);
}

// Static implementation

static int	base_digit(char c, int base)
{
	char	*low;
	char	*up;
	int		i;

	low = "0123456789abcdef";
	up = "0123456789ABCDEF";
	i = -1;
	while (++i < base)
		if (c == low[i] || c == up[i])
			return (i);
	return (-1);
}
