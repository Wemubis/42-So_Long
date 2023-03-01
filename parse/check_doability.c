/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doability.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:09:24 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/01 17:17:43 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_the_char(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == 'E')
		game->check_e++;
	if (map[y][x] == 'C')
		game->check_c++;
}

static int	browse_the_map(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'E'
	|| map[y][x] == 'C')
	{
		check_the_char(game, map, x, y);
		browse_the_map(game, map, x, y + 1);
		browse_the_map(game, map, x, y - 1);
		browse_the_map(game, map, x + 1, y);
		browse_the_map(game, map, x - 1, y);
	}
	return (1);
}

void	check_if_doable(t_game *game, char **map)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	browse_the_map(game, map, x, y);
	if (game->check_c != game->count_c)
		ft_free_error("Some items are out of range", map);
	if (game->check_e != game->count_e)
		ft_free_error("The exit is out of range", map);
}