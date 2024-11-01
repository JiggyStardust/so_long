/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:58 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/01 16:23:28 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**create_map(char *path_to_map)
{
	int		fd;
	char	*map_line;
	char	**map;
	char	*line;

	ft_printf("create map begininning");
	fd = open(path_to_map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("There's no such map my lady, may I assume master tested me with a typo?");
		return (0);
	}
	map_line = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("we entered the loop\n");
		ft_printf("mapline: \n%s\n", map_line);
		map_line = ft_strjoin(map_line, line);
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("mapline: \n%s\n", map_line);
	ft_printf("JOU");
	free(line);
	ft_printf("mapline: \n%s\n", map_line);
	map = ft_split(map_line, '\n');
	close(fd);
	return (map);
}
