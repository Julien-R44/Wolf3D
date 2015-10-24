/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 00:18:14 by y0ja              #+#    #+#             */
/*   Updated: 2015/03/24 20:57:30 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		check_lign(t_map *map, char **buf)
{
	int i;

	i = 0;
	while (buf[i])
		i++;
	if (map->width == 0)
		map->width = i;
	else
	{
		if (i != map->width)
			ft_error(1);
	}
}

static int		map_height(char *file)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error(0);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		i++;
	}
	close(fd);
	return (i);
}

static void		ft_arraydel(char ***tab)
{
	int len;

	len = 0;
	while ((*tab)[len] != NULL)
	{
		free((*tab)[len]);
		len++;
	}
	free((*tab));
}

static void		map_parser2(t_map *map, char *line, int i, int j)
{
	char	**buf;

	buf = NULL;
	buf = ft_strsplit(line, ' ');
	ft_strdel(&line);
	check_lign(map, buf);
	if ((map->map[j] = (int *)ft_memalloc(sizeof(int) *
	map->width + 1)) == NULL)
		ft_error(-2);
	while (buf[i])
	{
		map->map[j][i] = ft_atoi(buf[i]);
		i++;
	}
	ft_arraydel(&buf);
	map->map[j][i] = 0;
}

void			map_parser(t_map *map)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((fd = open("map/real.map", O_RDONLY)) == -1)
		ft_error(0);
	if (!(map->map = (int **)ft_memalloc(sizeof(int *) *
			map_height("map/real.map") + 1)))
		ft_error(2);
	while (get_next_line(fd, &line) > 0)
	{
		map_parser2(map, line, i, j);
		i = 0;
		j++;
		map->height++;
	}
	map->map[j] = NULL;
	close(fd);
}
