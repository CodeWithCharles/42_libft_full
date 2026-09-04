/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:39:40 by cpoulain          #+#    #+#             */
/*   Updated: 2026/09/04 17:43:14 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_byte			*out;
	const t_byte	*in;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	out = (t_byte *)dest;
	in = (const t_byte *)src;
	i = 0;
	while (i + sizeof(unsigned long) <= n)
	{
		*(unsigned long *)(out + i) = *(const unsigned long *)(in + i);
		i += sizeof(unsigned long);
	}
	while (i < n)
	{
		out[i] = in[i];
		i++;
	}
	return (dest);
}
