/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:58 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/04 12:02:20 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


char	*create_mapstr(int fd)
{
	char	*map;
	char	*line;
	char	*temp;

	map = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = map;
		map = ft_strjoin(map, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	return (map);
}


char	**create_map(char *path_to_map)
{
	int		fd;
	char	*map_line;
	char	**map;

	fd = open(path_to_map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("There's no such /map/path my lady, may I assume master tested me with a typo?");
		return (0);
	}
	map_line = create_mapstr(fd);
	ft_printf("mapline: \n%s\n", map_line);
	map = ft_split(map_line, '\n');
	free(map_line);
	close(fd);
	return (map);
}
