/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:13:16 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/15 18:41:48 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	len_nb_power_ten(int n)
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

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		len;

	nb = n;
	len = len_nb_power_ten(n);
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
	{
		nb *= -1;
		write (fd, "-", 1);
	}
	while (len)
	{
		ft_putchar_fd(nb / len + 48, fd);
		nb %= len;
		len /= 10;
	}
}
