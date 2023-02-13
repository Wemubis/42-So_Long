/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:14:40 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/13 17:07:58 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps;
	unsigned char	*sp;
	size_t			i;

	i = 0;
	ps = (unsigned char *)s1;
	sp = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ps[i] != sp[i])
			return (ps[i] - sp[i]);
		i++;
	}
	return (0);
}
