/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:54:37 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/13 20:40:24 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*----------------- HEADERS -----------------*/
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/libft.h"
# include "struct.h"
# include <errno.h>

/*------------------- LIST ------------------*/
void	*pop(t_lst *head);
int		lst_size(t_lst *lst);
t_lst	*new_element(char *data);
void	add_back(t_lst **lst, t_lst *new);

/*------------------ UTILS ------------------*/
void	error(char *str);
char	**parse_file(char *file_name);
void	check_map_validity(char **map);

/*------------------ WIDNOW -----------------*/


/*------------------ PLAYER -----------------*/

#endif