/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:32:29 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/09 17:52:58 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_to_win(t_start *s, t_image *img, void *sprt)
{
	mlx_put_image_to_window(s->ptr, s->win, sprt, (s->player.x * img->width),
			(s->player.y * img->height));
}

void	mlx_free_sprites(t_image *img, void *ptr)
{
	mlx_destroy_image(ptr, img->img_exit);
	mlx_destroy_image(ptr, img->img_floor);
	mlx_destroy_image(ptr, img->img_item);
	mlx_destroy_image(ptr, img->img_wall);
	mlx_destroy_image(ptr, img->img_player);
}
