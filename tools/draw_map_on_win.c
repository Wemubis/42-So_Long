/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_on_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:27:58 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/01 19:00:47 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_scene(t_start *start, t_image *img, void *ptr, void *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < start->win_h)
	{
		x = 0;
		while (x < start->win_w)
		{
			mlx_put_image_to_window(ptr, win, img->img_floor, x, y);
			x++;
		}
		y++;
	}
}

void	draw_furnitures(t_start *s, t_image *img, void *image, int x, int y)
{
	mlx_put_image_to_window(s->ptr, s->win, image, x * img->width,
				y * img->height);
}

void	draw_player(t_coord player, t_image *img, void *ptr, void *win)
{
	mlx_put_image_to_window(ptr, win, img->img_player, player.x * img->width,
				player.y * img->height);
}

void	draw_map_on_win(t_start *start, t_image *img)
{
	int	x;
	int	y;

	y = 0;
	draw_scene(start, img, start->ptr, start->win);
	while (y < start->win_h)
	{
		x = 0;
		while (x < start->win_w)
		{
			if (start->map[y][x] == '1')
				draw_furnitures(start, img, img->img_wall, x, y);
			else if (start->map[y][x] == 'C')
				draw_furnitures(start, img, img->img_item, x, y);
			else if (start->map[y][x] == 'E')
				draw_furnitures(start, img, img->img_exit, x, y);
			else if (start->map[y][x] == 'P')
				draw_player(start->game->player, img, start->ptr, start->win);
			x++;
		}
		y++;
	}
}