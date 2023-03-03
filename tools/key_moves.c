/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:14:01 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/03 15:31:49 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	esc_press(t_start *start)
{
	ft_printf("You noob!!!\n Even a lil baby would have done this map!! ;)\n");
	kill_all(start);
}

static void	collect_item(t_start *s, t_game *game, t_image *img)
{
	game->count_c--;
	s->map[game->player.y][game->player.x] = '0';
	print_to_win(s, s->game, img, img->img_floor);
}

static void	move(t_start *s,t_image *img, char axis, int dir)
{
	int	x;
	int	y;

	x = s->game->player.x;
	y = s->game->player.y;
	print_to_win(s, s->game, img, img->img_floor);
	if (axis == 'x')
	{
		if (s->map[y][x + 1 * dir] != '1' && s->map[y][x + 1 * dir] != 'E')
			s->game->player.x += 1 * dir;
		else if (s->map[y][x + 1 * dir] == 'E' && s->game->count_c)
			ft_printf("Collect all items, before leaving !!");
	}
	else if (axis == 'y')
	{
		if (s->map[y + 1 * dir][x] != '1' && s->map[y + 1 * dir][x] != 'E')
			s->game->player.y += 1 * dir;
		else if (s->map[y + 1 * dir][x] == 'E' && s->game->count_c)
			ft_printf("Collect all items, before leaving !!");
	}
	if (s->map[s->game->player.y][s->game->player.x] == 'C')
		collect_item(s, s->game, img);
	print_to_win(s, s->game, img, img->img_player);
	mlx_do_sync(s->ptr);
	ft_printf("Number of moves : %d", ++s->game->nb_move);
}

static void	finish_game(t_start *start)
{}

int	key_press(int press, t_start *start)
{
	if (press == ESC)
		esc_press(start);
	else if (press == W)
		move(start, start->img, 'y', UP);
	else if (press == A)
		move(start, start->img, 'x', LEFT);
	else if (press == S)
		move(start, start->img, 'y', DOWN);
	else if (press == D)
		move(start, start->img, 'x', RIGHT);
	if (start->map[start->game->player.y][start->game->player.x] == 'E'
		&& start->game->count_c == 0)
		finish_game(start);
	return (0);
}
