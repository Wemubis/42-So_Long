/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:32:29 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/03 12:50:36 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*xpm_to_img(void *ptr, char *path, int width, int height)
{
	mlx_xpm_file_to_image(ptr, path, width, height);
}

void	mlx_free_sprites(t_image *img, void *ptr)
{
	mlx_destroy_image(ptr, img->img_exit);
	mlx_destroy_image(ptr, img->img_floor);
	mlx_destroy_image(ptr, img->img_item);
	mlx_destroy_image(ptr, img->img_wall);
	mlx_destroy_image(ptr, img->img_player);
}
