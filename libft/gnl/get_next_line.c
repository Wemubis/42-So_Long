/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:09:35 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/23 17:14:05 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*keep_right(char *string)
{
	char	*dst;
	int		i;
	int		j;

	if (!string)
		return (NULL);
	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (!string[i])
		return (free(string), NULL);
	dst = malloc(sizeof(char) * (gnl_strlen(string) - i + 1));
	if (!dst)
		return (free(string), NULL);
	j = 0;
	i++;
	while (string[i])
		dst[j++] = string[i++];
	dst[j] = '\0';
	if (!dst[0])
		return (free(string), free(dst), NULL);
	return (free(string), dst);
}

static char	*read_save_string(int fd, char *string, int rt)
{
	char	*buff;
	char	*stash;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(string), NULL);
	while (rt > 0 && !gnl_strchr(string, '\n'))
	{
		rt = read(fd, buff, BUFFER_SIZE);
		if (rt == -1)
			return (free(buff), free(string), NULL);
		if (rt == 0)
			break ;
		buff[rt] = '\0';
		stash = string;
		string = gnl_strjoin(stash, buff);
		free(stash);
	}
	return (free(buff), string);
}

char	*get_next_line(int fd)
{
	static char	*string[1024];
	char		*stash;
	int			rt;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	rt = 1;
	string[fd] = read_save_string(fd, string[fd], rt);
	if (!string[fd])
		return (NULL);
	stash = keep_left(string[fd]);
	if (!stash)
		return (free(string[fd]), string[fd] = NULL, NULL);
	string[fd] = keep_right(string[fd]);
	return (stash);
}
