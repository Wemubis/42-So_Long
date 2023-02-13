/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:17:34 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/15 18:51:52 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_str(char const *s, char c)
{
	int	boolean;
	int	nb;

	boolean = 0;
	nb = 0;
	while (*s)
	{
		if (*s != c && !boolean)
		{
			boolean = 1;
			nb++;
		}
		else if (*s == c)
			boolean = 0;
		s++;
	}
	return (nb);
}

static int	nb_char_str(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static int	free_dst(char **dst, int j)
{
	j++;
	while (j-- > 0)
		free(dst[j]);
	free(dst);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		x;
	char	**dst;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	dst = malloc(sizeof(char *) * (nb_str(s, c) + 1));
	if (!dst)
		return (NULL);
	while (++j < (nb_str(s, c)))
	{
		while (s[i] == c)
			i++;
		x = nb_char_str(s, c, i);
		dst[j] = ft_substr(s, (unsigned int)i, (size_t)x);
		if (!dst[j])
			if (free_dst(dst, j))
				return (NULL);
		i += x;
	}
	dst[j] = NULL;
	return (dst);
}
