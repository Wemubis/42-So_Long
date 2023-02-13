/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:35:58 by mle-boud          #+#    #+#             */
/*   Updated: 2022/12/11 19:35:58 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_length(long nb)
{
	long	len;

	len = 1;
	nb /= 10;
	while (nb)
	{
		nb /= 10;
		len *= 10;
	}
	return (len);
}

void	ft_putnbr(int n)
{
	long	len;
	long	nb;

	nb = n;
	len = ft_length(nb);
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (len)
	{
		ft_putchar(nb / len + 48);
		nb %= len;
		len /= 10;
	}
}
