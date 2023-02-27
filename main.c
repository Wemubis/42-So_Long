/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:42:27 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/27 21:06:15 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_variables(t_game *game)
{
	game->player_move = 0;
	game->count_c = 0;
	game->count_p = 0;
	game->count_e = 0;
}

int	main(int ac, char **av)
{
	t_start	*start;

	if (ac == 2)
	{
		start->map = parse_file(av[1]);
		set_variables(start->game);
		check_map_validity(start);
		start_game(start);
	}
	else
		error("- Usage : ./so_long >map.ber< -");
	// need to free;
	return (0);
}
