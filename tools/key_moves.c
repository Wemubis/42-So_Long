/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:14:01 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/03 13:22:56 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	esc_press(t_start *start)
{
	ft_printf("You noob!!!\n Even a lil baby would have done this map!! ;)\n");
	kill_all(start);
}

static void	player_move(t_start *start, char axis, int dir)
{}

static void	finish_game(t_start *start)
{}

int	key_press(int press, t_start *start)
{
	if (press == ESC)
		esc_press(start);
	else if (press == W)
		player_move(start, 'y', UP);
	else if (press == A)
		player_move(start, 'x', LEFT);
	else if (press == S)
		player_move(start, 'y', DOWN);
	else if (press == D)
		player_move(start, 'x', RIGHT);
	if (start->map[start->game->player.y][start->game->player.x] == 'E')
		finish_game(start);
	return (0);
}
