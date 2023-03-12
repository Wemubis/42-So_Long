/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:14:01 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/12 12:18:17 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	close_game(t_start *start, int k)
{
	if (k == 0)
		ft_printf("You noob!!!\nEven a lil baby would have done this map!! ;)\n");
	else
		ft_printf("Well done bruuh!! You're THE man\n");
	end(start);
}

static int	nb_item(t_start *s)
{
	int	x;
	int	y;
	int	nb_item;

	y = 0;
	nb_item = 0;
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == 'C')
				nb_item++;
			x++;
		}
		y++;
	}
	return (nb_item);
}

static void	move_y_axis(t_start *s, int dir)
{
	int	x;
	int	y;

	x = s->player.x;
	y = s->player.y;
	if (s->map[y + 1 * dir][x] != '1' && (s->map[y + 1 * dir][x] != 'E'
		|| !nb_item(s)))
		s->player.y += 1 * dir;
	else if (s->map[y + 1 * dir][x] == 'E' && nb_item(s))
	{
		ft_printf("Collect all the items, before leaving !!\n");
		return ;
	}
	if (s->map[s->player.y][x] == 'E' && !nb_item(s))
		close_game(s, 1);
	s->map[y][x] = '0';
	s->map[s->player.y][x] = 'P';
	if (y != s->player.y)
		++s->nb_move;
}

static void	move_x_axis(t_start *s, int dir)
{
	int	x;
	int	y;

	x = s->player.x;
	y = s->player.y;
	if (s->map[y][x + 1 * dir] != '1' && (s->map[y][x + 1 * dir] != 'E'
		|| !nb_item(s)))
		s->player.x += 1 * dir;
	else if (s->map[y][x + 1 * dir] == 'E' && nb_item(s))
	{
		ft_printf("Collect all the items, before leaving !!\n");
		return ;
	}
	if (s->map[y][s->player.x] == 'E' && !nb_item(s))
		close_game(s, 1);
	s->map[y][x] = '0';
	s->map[y][s->player.x] = 'P';
	if (x != s->player.x)
		++s->nb_move;
}

int	key_press(int press, t_start *sl)
{
	int	move;

	move = sl->nb_move;
	if (press == XK_Escape)
		close_game(sl, 0);
	else if (press == XK_w)
		move_y_axis(sl, UP);
	else if (press == XK_a)
		move_x_axis(sl, LEFT);
	else if (press == XK_s)
		move_y_axis(sl, DOWN);
	else if (press == XK_d)
		move_x_axis(sl, RIGHT);
	if (move != sl->nb_move)
		ft_printf("Number of moves : %d\n", sl->nb_move);
	return (0);
}
