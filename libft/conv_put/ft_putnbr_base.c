/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:44:05 by mle-boud          #+#    #+#             */
/*   Updated: 2022/12/11 19:44:05 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_length_nbr(long len_b, long nb)
{
	long	l;

	if (len_b <= 1)
		return (1);
	l = 1;
	while (nb != 0)
	{
		nb /= len_b;
		l *= len_b;
	}
	return (l);
}

static int	ft_check(char *base, long len_b)
{
	int	j;
	int	i;

	if (!base[0] || len_b == 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] <= ' ' || base[i] >= '~')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
	}
	return (1);
}

void	ft_putnbr_base(int n, char *base)
{
	long	len;
	long	nb;
	int		len_b;

	len_b = ft_strlen(base);
	if (!ft_check(base, len_b))
		return ;
	nb = n;
	len = ft_length_nbr(len_b, nb);
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		nb *= (-1);
		write(1, "-", 1);
	}
	while (len)
	{
		ft_putchar(base[nb / len]);
		nb %= len;
		len /= len_b;
	}
}
