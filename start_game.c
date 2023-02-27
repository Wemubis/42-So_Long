/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:19:03 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/27 23:47:45 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_img(void *ptr, t_image *img)
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

static void	init_window(char **map, t_image *img, void *win, void *ptr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
		i++;
	win = mlx_new_window(ptr, (len * img->width), (i * img->height), "So_long");
	if (!win)
		kill_all();
}

void	start_game(t_start *start)
{
	start->ptr = mlx_init();
	open_img(start->ptr, start->img);
	init_window(start->map, start->img, start->win, start->ptr);
	// mettre des hooks
	mlx_loop(start->ptr);
}
