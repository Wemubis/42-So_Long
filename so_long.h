/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:54:37 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/23 12:21:24 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*----------------- HEADERS -----------------*/
# include <errno.h>
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
void	add_back(t_lst **lst, t_lst *new);

/*------------------ UTILS ------------------*/
void	error(char *str);
void	ft_free_error(char *str, char **map);
char	**parse_file(char *file_name);
void	check_map_validity(char **map);

/*------------------ WIDNOW -----------------*/


/*------------------ PLAYER -----------------*/

#endif