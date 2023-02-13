/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:32:11 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/18 16:21:10 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int		a;
	int					s;
	int					i;

	a = 0;
	i = 0;
	s = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		if (a != ((a * 10 + (s * (str[i] - 48))) / 10))
			return ((int)((s + 1) / -2));
		a = a * 10 + ((str[i] - 48) * s);
		i++;
	}
	return ((int)a);
}
