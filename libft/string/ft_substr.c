/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:04:00 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/18 16:57:42 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
	{
		dst = malloc(sizeof(char) * 1);
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (ft_strlen(s) - start > len)
		dst = malloc(sizeof(char) * (len + 1));
	else
		dst = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!dst)
		return (NULL);
	if (ft_strlen(s) - start > len)
	{
		ft_strlcpy(dst, s + start, len + 1);
		return (dst);
	}
	ft_strlcpy(dst, s + start, ft_strlen(s) - start + 1);
	return (dst);
}
