/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:35:53 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/02 16:38:14 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Static prototypes

static void	_swap(
				unsigned char	*a,
				unsigned char	*b
				);

// Function implementations

void	ft_memswap(
	void	*_a,
	void	*_b,
	size_t	n
)
{
	unsigned char	*a;
	unsigned char	*b;

	a = _a;
	b = _b;
	while (n--)
		_swap(a++, b++);
}

// Static implementation

static void	_swap(
	unsigned char	*a,
	unsigned char	*b
)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
