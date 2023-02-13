/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:35:34 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/29 13:42:32 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	len_nb(int n)
{
	long	len;

	len = 1;
	n /= 10;
	while (n)
	{
		len *= 10;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr_printf(int n)
{
	long	nb;
	int		len;
	int		ret;

	len = len_nb(n);
	nb = n;
	ret = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		nb *= -1;
		ret += write(1, "-", 1);
	}
	while (len)
	{
		ft_putchar(nb / len + '0');
		nb %= len;
		len /= 10;
		ret++;
	}
	return (ret);
}
