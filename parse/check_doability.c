/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doability.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:09:24 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/09 17:46:02 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_the_char(t_start *game, int x, int y)
{
	if (game->map[y][x] == 'p')
		game->map[y][x] = 'P';
	if (game->map[y][x] == 'o')
		game->map[y][x] = '0';
	if (game->map[y][x] == 'e')
	{
		game->map[y][x] = 'E';
		game->check_e++;
	}
	if (game->map[y][x] == 'c')
	{
		game->map[y][x] = 'C';
		game->check_c++;
	}
}

static int	browse_the_map(t_start *game, int x, int y)
{
	if (game->map[y][x] == 'o' || game->map[y][x] == 'p' ||
	game->map[y][x] == 'e' || game->map[y][x] == 'c')
	{
		check_the_char(game, x, y);
		browse_the_map(game, x, y + 1);
		browse_the_map(game, x, y - 1);
		browse_the_map(game, x + 1, y);
		browse_the_map(game, x - 1, y);
	}
	return (1);
}

void	check_if_doable(t_start *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	browse_the_map(game, x, y);
	if (game->check_c != game->count_c)
		ft_free_error("Some items are out of range", game->map);
	if (game->check_e != game->count_e)
		ft_free_error("The exit is out of range", game->map);
}