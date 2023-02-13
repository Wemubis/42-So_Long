/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:29:58 by mle-boud          #+#    #+#             */
/*   Updated: 2023/02/13 20:30:42 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_map(char *file_name)
{
	char	*extention;
	int		fd;

	extention = ft_strrchr(file_name, '.');
	if (extention == NULL || ft_strcmp(".ber", extention) != 0)
		error("Invalid file type");
	fd = open(file_name, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		error("Is a directory and not a file");
	}
	fd = open(file_name, O_RDONLY | O_NOFOLLOW);
	if (fd == -1)
		error(strerror(errno));
	return (fd);
}

static char	**list_to_arr(t_lst *list)
{
	char	**arr;
	int		nb_line;
	int		i;

	i = 0;
	nb_line = lst_size(list);
	arr = malloc(sizeof(char *) * (nb_line + 1));
	if (!arr)
		error("malloc");
	while (list)
	{
		arr[i++] = ft_strdup(list->data);
		if (list->next != NULL)
		{
			list = list->next;
			pop(list->prev);
		}
		else
			pop(list);
	}
	arr[i] = NULL;
	return (arr);
}

char	**parse_file(char *file_name)
{
	t_lst	*list;
	char	**map;
	char	*ret[2];
	int		fd;

	list = NULL;
	fd = open_map(file_name);
	ret[0] = "a";
	while (ret[0] != NULL)
	{
		ret[0] = get_next_line(fd);
		ret[1] = ret[0];
		if (ret[1] != NULL && ft_strlen(ret[1]) != 0)
		{
			add_back(&list, new_element(ft_strdup(ret[1])));
			free(ret[1]);
		}
	}
	close(fd);
	map = list_to_arr(list);
	return (map);
}
