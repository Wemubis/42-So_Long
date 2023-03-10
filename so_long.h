/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:54:37 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/10 19:46:21 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*----------------- HEADERS -----------------*/
# include <errno.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include "libft/libft.h"

/*---------- DEFINE, MORE READABLE ----------*/
# define ESC 27
# define W 87
# define A 65
# define S 83
# define D 68
# define UP 1
# define DOWN -1
# define LEFT -1
# define RIGHT 1

/*--------------- Coordinate ---------------*/
typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

/*----------------- Start ------------------*/
typedef struct s_start
{
	void	*ptr;
	void	*win;
	char	**map;
	int		win_h;
	int		win_w;
	t_coord	player;
	int		nb_move;
	int		count_p;
	int		count_c;
	int		count_e;
	int		check_c;
	int		check_e;
	int		height;
	int		width;
	char	*p_exit;
	char	*floor;
	char	*wall;
	char	*item;
	char	*p_player;
	void	*img_exit;
	void	*img_floor;
	void	*img_wall;
	void	*img_item;
	void	*img_player;
}		t_start;

/*------------------- GAME ------------------*/
void	start_game(t_start *sl);
int		key_press(int press, t_start *start);

/*------------------ TOOLS ------------------*/
void	error(char *str);
int		end(t_start *start);
int		kill_all(t_start *start);
void	ft_free_error(char *str, char **map);
char	**parse_file(char *file_name);
void	check_map_validity(t_start *start);
void	check_if_doable(t_start *game);

/*------------------ WIDNOW -----------------*/
void	mlx_free_sprites(t_start *sl);
void	print_to_win(t_start *s, void *img);
void	draw_map_on_win(t_start *sl);

#endif