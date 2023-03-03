/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:30:18 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/03 22:38:32 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char *str)
{
	ft_printf("Error :\n %s\n", str);
	exit(EXIT_FAILURE);
}

static void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	ft_free_error(char *str, char **map)
{
	ft_free(map);
	error(str);
}

int	end(t_start *start)
{
	ft_free(start->map);
	mlx_free_sprites(start->img, start->ptr);
	mlx_destroy_window(start->ptr, start->win);
	exit(EXIT_SUCCESS);
}

int	kill_all(t_start *start)
{
	ft_free(start->map);
	mlx_free_sprites(start->img, start->ptr);
	mlx_destroy_window(start->ptr, start->win);
	exit(EXIT_FAILURE);
}
