/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:49:08 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/29 16:18:59 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_conversion(va_list arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (format == 's')
		return (ft_putstr_printf(va_arg(arg, char *)));
	if (format == 'p')
	{
		write(1, "0x", 2);
		return (ft_ptr_b_printf(va_arg(arg, void *), "0123456789abcdef") + 2);
	}
	if (format == 'd' || format == 'i')
		return (ft_putnbr_printf(va_arg(arg, int)));
	if (format == 'u')
		return (ft_putnbr_unsigned_printf(va_arg(arg, unsigned int)));
	if (format == 'x')
		return (ft_nbr_b_printf(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_nbr_b_printf(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else
		return (write(1, &format, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		ret;
	int		i;

	if (!format)
		return (0);
	if (write(1, NULL, 0) < 0)
		return (-1);
	va_start(arg, format);
	ret = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		else if (format[i] == '%')
			ret += ft_conversion(arg, format[++i]);
		else
			ret += write(1, &format[i], 1);
	}
	va_end(arg);
	return (ret);
}
