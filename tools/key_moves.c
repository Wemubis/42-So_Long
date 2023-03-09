/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:14:01 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/09 17:56:19 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	esc_press(t_start *start)
{
	ft_printf("You noob!!!\n Even a lil baby would have done this map!! ;)\n");
	end(start);
}

static void	collect_item(t_start *s, t_image *img)
{
	s->count_c--;
	s->map[s->player.y][s->player.x] = '0';
	print_to_win(s, img, img->img_floor);
}

static void	move(t_start *s,t_image *img, char axis, int dir)
{
	int	x;
	int	y;

	x = s->player.x;
	y = s->player.y;
	print_to_win(s, img, img->img_floor);
	if (axis == 'x')
	{
		if (s->map[y][x + 1 * dir] != '1' && s->map[y][x + 1 * dir] != 'E')
			s->player.x += 1 * dir;
		else if (s->map[y][x + 1 * dir] == 'E' && s->count_c)
			ft_printf("Collect all items, before leaving !!");
	}
	else if (axis == 'y')
	{
		if (s->map[y + 1 * dir][x] != '1' && s->map[y + 1 * dir][x] != 'E')
			s->player.y += 1 * dir;
		else if (s->map[y + 1 * dir][x] == 'E' && s->count_c)
			ft_printf("Collect all items, before leaving !!");
	}
	if (s->map[s->player.y][s->player.x] == 'C')
		collect_item(s, img);
	print_to_win(s, img, img->img_player);
	mlx_do_sync(s->ptr);
	ft_printf("Number of moves : %d", ++s->nb_move);
}

static void	finish_game(t_start *start)
{
	ft_printf("Well done bro!! You're THE man");
	end(start);
}

int	key_press(int press, t_start *sl)
{
	if (press == ESC)
		esc_press(sl);
	else if (press == W)
		move(sl, sl->img, 'y', UP);
	else if (press == A)
		move(sl, sl->img, 'x', LEFT);
	else if (press == S)
		move(sl, sl->img, 'y', DOWN);
	else if (press == D)
		move(sl, sl->img, 'x', RIGHT);
	if (sl->map[sl->player.y][sl->player.x] == 'E' && sl->count_c == 0)
		finish_game(sl);
	return (0);
}
