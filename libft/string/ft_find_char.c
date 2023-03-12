/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:55:14 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/03 22:58:09 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	ft_find_char(const char *s, int c)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)s;
	while (i < ft_strlen(dst))
	{
		if (dst[i] == (unsigned char)c)
			return (dst[i]);
		i++;
	}
	if (!dst[i] && c == '\0')
		return (dst[i]);
	return (0);
}
