/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:17:29 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/15 15:21:38 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dst;
	long	nb;
	int		len;

	nb = n;
	len = len_nb(nb);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	if (nb == 0)
		dst[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		dst[0] = '-';
	}
	dst[len] = '\0';
	if (nb > 0)
		len--;
	while (nb > 0)
	{
		dst[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (dst);
}
