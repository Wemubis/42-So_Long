/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:54:37 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/03 13:12:26 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*----------------- HEADERS -----------------*/
# include <errno.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/libft.h"
# include "struct.h"

/*---------- DEFINE, MORE READABLE ----------*/
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 1
# define DOWN -1
# define LEFT -1
# define RIGHT 1

/*------------------- GAME ------------------*/
void	start_game(t_start *start);
int		key_moves(int press, t_start *start);

/*------------------- LIST ------------------*/
void	*pop(t_lst *head);
int		lst_size(t_lst *lst);
t_lst	*new_element(char *data);
void	add_back(t_lst **lst, t_lst *new_one);

/*------------------ TOOLS ------------------*/
void	error(char *str);
int		kill_all(t_start *start);
void	ft_free_error(char *str, char **map);
char	**parse_file(char *file_name);
void	check_map_validity(t_start *start);
void	check_if_doable(t_game *game, char **map);

/*------------------ WIDNOW -----------------*/
void	mlx_free_sprites(t_image *img, void *ptr);
void	*xpm_to_img(void *ptr, char *path, int width, int height);
void	draw_map_on_win(t_start *start, t_image *img);
void	draw_player(t_coord player, t_image *img, void *ptr, void *win);
void	draw_furnitures(t_start *s, t_image *img, void *image, int x, int y);

#endif