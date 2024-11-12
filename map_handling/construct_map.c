/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:58 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/12 15:35:16 by sniemela         ###   ########.fr       */
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
		if (!map)
		{
			ft_printf("Error\ncreate_map() ft_strjoin\n");
			return (NULL);
		}
		line = get_next_line(fd);
	}
	return (map);
}

static bool	emptylines(const char *map_line)
{
	int	len;

	len = ft_strlen(map_line);
	if (map_line[len - 1] == '\n' && map_line[len - 2] == '\n')
	{
		ft_printf("Error\nEmpty lines in the map.\n");
		return (true);
	}
	return (false);
}

static bool	valid_filename(char *path)
{
	int		len;

	len = ft_strlen(path);
	if (ft_strncmp(&path[len - 4], ".ber", 4) != 0 || path[len - 5] == '/')
	{
		ft_printf("Error\nFile name should be '*.ber'.\n");
		return (false);
	}
	return (true);
}

char	**create_map(char *path)
{
	int		fd;
	char	*map_line;
	char	**map;

	if (!valid_filename(path))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nThere's no such /map/path my lady.\n");
		return (0);
	}
	map_line = create_mapstr(fd);
	if (!map_line)
		return (NULL);
	if (emptylines(map_line))
	{
		free(map_line);
		return (NULL);
	}
	map = ft_split(map_line, '\n');
	free(map_line);
	close(fd);
	return (map);
}
