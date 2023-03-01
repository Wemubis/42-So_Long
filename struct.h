/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:26:35 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/01 18:25:46 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

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

/*------------------ Game ------------------*/
typedef struct s_game
{
	t_coord	player;
	int		nb_move;
	int		count_p;
	int		count_c;
	int		count_e;
	int		check_c;
	int		check_e;
}		t_game;

/*----------------- Image ------------------*/
typedef struct s_image
{
	int		height;
	int		width;
	char	*p_exit;
	char	*floor;
	char	*wall;
	char	*item;
	char	*player;
	void	*img_exit;
	void	*img_floor;
	void	*img_wall;
	void	*img_item;
	void	*img_player;
}		t_image;

/*----------------- Start ------------------*/
typedef struct s_start
{
	void	*ptr;
	void	*win;
	char	**map;
	int		win_h;
	int		win_w;
	t_game	*game;
	t_image	*img;
}		t_start;

#endif