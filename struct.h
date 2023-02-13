/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:26:35 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/13 17:18:47 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H


/*------------------ List ------------------*/
typedef struct s_lst
{
	char			*data;
	struct s_lst	*prev;
	struct s_lst	*next;
}		t_lst;

/*--------------- Coordinate ---------------*/
typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

/*------------------ Keys ------------------*/
typedef struct s_keys
{
	int	up;
	int	down;
	int	left;
	int	right;
}		t_keys;

/*------------------ Game ------------------*/
typedef struct s_game
{
	t_keys	*go;
	t_coord	*player;
	t_coord	*door;
	t_coord	*item;
	// int		player_move;
	// int		player_coll;
	// int		count_coll;
	// int		count_escape;
	// int		count_player;
}		t_game;

/*----------------- Start ------------------*/
typedef struct s_start
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	t_game	*game;
	t_img	*mlx_img;
	t_img	*player;
	t_img	*door;
	t_img	*item;
	t_img	*wall;
	t_img	*ground;
}		t_start;

#endif