/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_on_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:27:58 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/10 19:46:12 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_scene(t_start *sl)
{
	int	x;
	int	y;

	y = 0;
	while (sl->map[y])
	{
		x = 0;
		while (sl->map[y][x])
		{
			if (sl->map[y][x] == '1')
				mlx_put_image_to_window(sl->ptr, sl->win, sl->img_wall, x, y);
			else if (sl->map[y][x] == '0')
				mlx_put_image_to_window(sl->ptr, sl->win, sl->img_floor, x, y);
			x++;
		}
		y++;
	}
}

void	draw_map_on_win(t_start *sl)
{
	int	x;
	int	y;

	y = 0;
	draw_scene(sl);
	while (y < sl->win_h)
	{
		x = 0;
		while (x < sl->win_w)
		{
			if (sl->map[y][x] == 'C')
				mlx_put_image_to_window(sl->ptr, sl->win, sl->img_item,
					x * sl->width, y * sl->height);
			else if (sl->map[y][x] == 'E')
				mlx_put_image_to_window(sl->ptr, sl->win, sl->img_exit,
					x * sl->width, y * sl->height);
			else if (sl->map[y][x] == 'P')
				mlx_put_image_to_window(sl->ptr, sl->win, sl->img_player,
					x * sl->width, y * sl->height);
			x++;
		}
		y++;
	}
}