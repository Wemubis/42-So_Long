/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:55:25 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/13 22:47:15 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	trim_line(t_start *start)
{
	int		i;
	char	*tmp;

	i = 0;
	while (start->map[i])
	{
		tmp = ft_chrtrim(start->map[i], '\n');
		free(start->map[i]);
		start->map[i] = tmp;
		if (!start->map[i])
			ft_free_error("Fail trim \\n", start->map);
		i++;
	}
}

void	check_2(t_start *start)
{
	size_t	len_line;
	int	i;

	i = -1;
	if (!start->map[0])
		ft_free_error("Empty map", start->map);
	while (start->map[++i])
		if (start->map[i][0] == '\n')
			ft_free_error("One line isn't valid", start->map);
	trim_line(start);
	i = 0;
	len_line = ft_strlen(start->map[i]);
	while (start->map[i])
	{
		if (len_line != ft_strlen(start->map[i]))
			ft_free_error("Not a rectangle", start->map);
		i++;
	}
}
