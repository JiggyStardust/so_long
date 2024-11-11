/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:37:58 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/11 11:34:58 by sniemela         ###   ########.fr       */
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

char	**create_map(char *path)
{
	int		fd;
	char	*map_line;
	char	**map;

	if (!ft_strnstr(path, ".ber", ft_strlen(path))
		|| ft_strnstr(path, ".ber", 9)
		|| ft_strnstr(path, ".ber", ft_strlen(path)) == path)
	{
		ft_printf("Error\nFile name should be '*.ber.'\n");
		return (NULL);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\nErrorThere's no such /map/path my lady.\n");
		return (0);
	}
	map_line = create_mapstr(fd);
	map = ft_split(map_line, '\n');
	free(map_line);
	close(fd);
	return (map);
}
