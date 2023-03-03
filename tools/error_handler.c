/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:30:18 by mle-boud          #+#    #+#             */
/*   Updated: 2023/03/03 12:59:23 by mle-boud         ###   ########.fr       */
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
}

void	ft_free_error(char *str, char **map)
{
	ft_free(map);
	map = NULL;
	error(str);
}

int	kill_all(t_start *start)
{
	exit(EXIT_SUCCESS);
}
