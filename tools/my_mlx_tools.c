/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:32:29 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/10 19:39:24 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_to_win(t_start *s, void *img)
{
	mlx_put_image_to_window(s->ptr, s->win, img, (s->player.x * s->width),
			(s->player.y * s->height));
}

void	mlx_free_sprites(t_start *sl)
{
	mlx_destroy_image(sl->ptr, sl->img_exit);
	mlx_destroy_image(sl->ptr, sl->img_floor);
	mlx_destroy_image(sl->ptr, sl->img_item);
	mlx_destroy_image(sl->ptr, sl->img_wall);
	mlx_destroy_image(sl->ptr, sl->img_player);
}
