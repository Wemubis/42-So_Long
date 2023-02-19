/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:40:57 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/19 23:02:23 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	array_size(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	is_valid_character(char element, char **map)
{
	int	valid;

	valid = ft_strchr("01ECP", element);
	if (!valid)
		ft_free_error("Character non valid", map);
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

static void	is_between(char *line, char **map)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = ft_strlen(line);
	while (line[i])
	{
		if (i == 0 || i == line_len - 1)
			if (line[i] != '1')
				ft_free_error("Not a valide middle line", map);
		else
			is_valid_character(line[i], map);
		i++;
	}
}

void	check_map_validity(char **map)
{
	int	i;
	int	line_len;
	int	map_height;

	i = 0;
	line_len = ft_strlen(map[i]);
	map_height = array_size(map);
	while (map[i])
	{
		if (i == 0 || i == map_height - 1)
			is_wall(map[i], map);
		else
			is_between(map[i], map);
		if (ft_strlen(map[i]) != line_len)
			ft_free_error("Not a rectangle", map);
		i++;
	}
}
