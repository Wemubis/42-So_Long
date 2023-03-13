/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:08:25 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/13 22:06:43 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_chrtrim(char const *s1, char c)
{
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	if (c == '\0')
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] == c)
		i++;
	len = ft_strlen(s1) - 1;
	while (s1[len] == c)
		len--;
	return (ft_substr(s1, i, len + 1 - i));
}
