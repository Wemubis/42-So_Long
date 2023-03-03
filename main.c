/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:42:27 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/03 13:13:24 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_variables(t_game *game)
{
	game->nb_move = 0;
	game->count_c = 0;
	game->count_p = 0;
	game->count_e = 0;
	game->check_c = 0;
	game->check_e = 0;
}

int	main(int ac, char **av)
{
	t_start	*start;

	if (ac == 2)
	{
		start->map = parse_file(av[1]);
		set_variables(start->game);
		check_map_validity(start);
		check_if_doable(start->game, start->map);
		start_game(start);
	}
	else
		error("- Usage : ./so_long >map.ber< -");
	return (0);
}
