/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:36:14 by cpoulain          #+#    #+#             */
/*   Updated: 2026/09/04 17:43:00 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	t_byte			*out;
	unsigned long	pattern;
	size_t			i;

	out = (t_byte *)s;
	pattern = (t_byte)c;
	pattern *= 0x0101010101010101UL;
	i = 0;
	while (i + sizeof(unsigned long) <= n)
	{
		*(unsigned long *)(out + i) = pattern;
		i += sizeof(unsigned long);
	}
	while (i < n)
		out[i++] = (t_byte)c;
	return (s);
}
