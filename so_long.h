/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:54:37 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/27 20:50:04 by mle-boud         ###   ########.fr       */
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

/*------------------- GAME ------------------*/
void	start_game(t_start *start);

/*------------------- LIST ------------------*/
void	*pop(t_lst *head);
int		lst_size(t_lst *lst);
t_lst	*new_element(char *data);
void	add_back(t_lst **lst, t_lst *new_one);

/*------------------ UTILS ------------------*/
void	error(char *str);
void	ft_free_error(char *str, char **map);
char	**parse_file(char *file_name);
void	check_map_validity(t_start *start);

/*------------------ WIDNOW -----------------*/
void	*xpm_to_img(void *ptr, char *path, int width, int height);

#endif