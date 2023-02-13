/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:31:44 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/18 14:25:32 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(char *str, char *tf)
{
	int	i;

	i = -1;
	while (str[++i] && tf[i])
		if (str[i] != tf[i])
			return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*tf;

	str = (char *)haystack;
	tf = (char *)needle;
	if (!ft_strlen(needle))
		return (str);
	if (!len)
		return (NULL);
	while (*str && ft_strlen((const char *)tf) <= len)
	{
		if ((*str == *tf) && ft_cmp(str, tf))
			return (str);
		str++;
		len--;
	}
	return (NULL);
}
