/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:40:57 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/12 12:26:51 by mle-boud         ###   ########.fr       */
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
	else if (valid == '0')
		start->map[y][x] = 'o';
	else if (valid == 'C')
	{
		start->map[y][x] = 'c';
		start->count_c++;
	}
	else if (valid == 'E')
	{
		start->map[y][x] = 'e';
		start->count_e++;
	}
	else if (valid == 'P')
	{
		start->map[y][x] = 'p';
		start->count_p++;
		start->player.x = x;
		start->player.y = y;
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
	line_len = ft_strlen(line) - 1;
	while (line[i])
	{
		if (i == 0 || i == line_len)
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

	i = 0;
	map_height = array_size(start->map) - 1;
	while (start->map[i])
	{
		if (i == 0 || i == map_height)
			is_wall(start->map[i], start->map);
		else
			is_between(start->map[i], start, i);
		if (i != 0 && ft_strlen(start->map[i - 1]) != ft_strlen(start->map[i]))
			ft_free_error("Not a rectangle map sry !!", start->map);
		i++;
	}
	if (start->count_p > 1 || start->count_e > 1)
		ft_free_error("More than ONE player/exit", start->map);
	if (start->count_c < 1)
		ft_free_error("Less than ONE item", start->map);
}
