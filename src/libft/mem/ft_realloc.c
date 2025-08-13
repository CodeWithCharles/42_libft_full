/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:11:06 by cpoulain          #+#    #+#             */
/*   Updated: 2025/08/13 13:16:29 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_reallocarray(
	void *ptr,
	size_t nmemb,
	size_t size,
	size_t old_nmemb
)
{
	size_t	total;
	size_t	old_total;
	void	*new_ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);

	total = nmemb * size;
	old_total = old_nmemb * size;

	new_ptr = malloc(total);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, (old_total < total) ? old_total : total);
		free(ptr);
	}
	return (new_ptr);
}
