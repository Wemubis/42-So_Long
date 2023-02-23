/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:42:27 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/23 12:21:39 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_start	*start;

	if (ac == 2)
	{
		start->map = parse_file(av[1]);
		check_map_validity(start->map);
		start_game(start);
	}
	else
		error("- Usage : ./so_long >map.ber< -");
	// need to free;
	return (0);
	
}
