/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:38:19 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 16:47:21 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Static prototypes

static void	*_partition(
				void	*base,
				size_t	nmemb,
				size_t	size,
				t_comparator cmp
				);

// Function implementation

void	ft_qsort(
	void *base,
	size_t nmemb,
	size_t size,
	t_comparator cmp
)
{
	void	*pivot;
	size_t	len;

	if (nmemb < 2)
		return ;
	pivot = _partition(base, nmemb, size, cmp);
	len = (char *)pivot - (char *)base;
	len /= size;
	ft_qsort(base, len, size, cmp);
	ft_qsort((char *)pivot + size, nmemb - len - 1, size, cmp);
}

// Static implementation

static void	*_partition(
	void *base,
	size_t nmemb,
	size_t size,
	t_comparator cmp
)
{
	void	*pivot;
	int		r;

	pivot = (char *)base + (nmemb - 1) * size;
	while (pivot > base)
	{
		r = cmp(base, pivot);
		if (r > 0)
		{
			ft_memswap(base, pivot, size);
			pivot -= size;
			ft_memswap(base, pivot, size);
		}
		else
			base += size;
	}
	return (pivot);
}
