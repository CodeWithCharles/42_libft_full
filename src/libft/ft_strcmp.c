/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:07:22 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/29 17:09:44 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(
	const char *s1,
	const char *s2
)
{
	while (*s1)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			break ;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
