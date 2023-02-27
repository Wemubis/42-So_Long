/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:42:27 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/27 16:08:41 by mle-boud         ###   ########.fr       */
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

static void	set_img(void *ptr, t_image *img)
{
	img->height = 64;
	img->width = 64;
	img->p_exit = "sprites/exit.xpm";
	img->floor = "sprites/floor.xpm";
	img->wall = "sprites/wall.xpm";
	img->item = "sprites/item.xpm";
	img->player = "sprites/player.xpm";
	img->img_exit = xpm_to_img(ptr, img->p_exit, img->width, img->height);
	img->img_floor = xpm_to_img(ptr, img->floor, img->width, img->height);
	img->img_wall = xpm_to_img(ptr, img->wall, img->width, img->height);
	img->img_item = xpm_to_img(ptr, img->item, img->width, img->height);
	img->img_player = xpm_to_img(ptr, img->player, img->width, img->height);
}

int	main(int ac, char **av)
{
	t_start	*start;

	if (ac == 2)
	{
		start->map = parse_file(av[1]);
		set_variables(start->game);
		check_map_validity(start);
		set_img(start->ptr, start->img);
		start_game(start);
	}
	else
		error("- Usage : ./so_long >map.ber< -");
	// need to free;
	return (0);
}
