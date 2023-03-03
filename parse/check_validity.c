/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:40:57 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/03 22:57:15 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	array_size(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	is_valid_character(char element, t_start *start, int y, int x)
{
	char	valid;

	valid = ft_find_char("01ECP", element);
	if (!valid)
		ft_free_error("Character non valid", start->map);
	else if (valid == 'C')
		start->game->count_c += 1;
	else if (valid == 'E')
		start->game->count_e += 1;
	else if (valid == 'P')
	{
		start->game->count_p += 1;
		start->game->player.x = x;
		start->game->player.y = y;
	}
}

static void	is_wall(char *line, char **map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			ft_free_error("Not an outside wall", map);
		i++;
	}
}

static void	is_between(char *line, t_start *start, int y)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = ft_strlen(line);
	while (line[i])
	{
		if (i == 0 || i == line_len - 1)
		{
			if (line[i] != '1')
				ft_free_error("Not a valide middle line", start->map);
		}
		else
			is_valid_character(line[i], start, y, i);
		i++;
	}
}

void	check_map_validity(t_start *start)
{
	int		i;
	int		map_height;
	size_t	line_len;

	i = 0;
	line_len = ft_strlen(start->map[i]);
	map_height = array_size(start->map);
	while (start->map[i])
	{
		if (i == 0 || i == map_height - 1)
			is_wall(start->map[i], start->map);
		else
			is_between(start->map[i], start, i);
		if (ft_strlen(start->map[i]) != line_len)
			ft_free_error("Not a rectangle", start->map);
		if (start->game->count_p > 1 || start->game->count_e > 1)
			ft_free_error("More than ONE player/exit", start->map);
		if (start->game->count_c > 1)
			ft_free_error("Less than ONE item", start->map);
		i++;
	}
}
