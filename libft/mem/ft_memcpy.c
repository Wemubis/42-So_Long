/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:13:56 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/09 16:57:21 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s1;
	char		*s2;
	size_t		i;

	i = -1;
	s1 = (const char *)src;
	s2 = (char *)dst;
	if ((s1 == NULL) && (s2 == NULL))
		return (NULL);
	while (++i < n)
		s2[i] = s1[i];
	return (dst);
}
