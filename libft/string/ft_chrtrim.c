/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:08:25 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/04 17:13:56 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_chrtrim(char const *s1, char c)
{
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!c)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && ft_memchr(&s1[i], c, ft_strlen(&s1[i])))
		i++;
	len = ft_strlen(s1) - 1;
	while (len && ft_memchr(&s1[len], c, ft_strlen(&s1[i])))
		len--;
	return (ft_substr(s1, i, len + 1 - i));
}
