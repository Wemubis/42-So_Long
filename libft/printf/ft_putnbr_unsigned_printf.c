/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:31:19 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/29 13:42:34 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	len_nb(unsigned int nb)
{
	long	len;

	len = 1;
	while (nb)
	{
		len *= 10;
		nb /= 10;
	}
	return (len);
}

int	ft_putnbr_unsigned_printf(unsigned int n)
{
	long	nb;
	int		len;
	int		ret;

	len = len_nb(n) / 10;
	nb = n;
	ret = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	while (len)
	{
		ft_putchar(nb / len + '0');
		nb %= len;
		len /= 10;
		ret++;
	}
	return (ret);
}
