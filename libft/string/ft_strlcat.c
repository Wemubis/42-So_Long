/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:34:43 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/14 16:12:51 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (dst == NULL && size == 0)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	x = ft_strlen((const char *)dst);
	if (size <= x)
		return (size + ft_strlen(src));
	while (src[i] && ((x + i) < (size - 1)))
	{
		dst[x + i] = src[i];
		i++;
	}
	dst[x + i] = '\0';
	return (x + ft_strlen(src));
}
