/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:26:35 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/23 22:14:35 by mle-boud         ###   ########.fr       */
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
	t_coord	*portal;
	t_coord	*item;
	int		player_move;
	int		count_p;
	int		count_c;
	int		count_e;
}		t_game;

/*----------------- Start ------------------*/
typedef struct s_start
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	int		nb_move;
	t_game	*game;
	t_img	*img;
	t_img	*player;
	t_img	*portal;
	t_img	*item;
	t_img	*wall;
	t_img	*ground;
}		t_start;

#endif