/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:42:08 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/04 14:44:28 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0' ||
		map[y][x] == 'F' || map[y][x] == '1')
			return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	flood_the_map(char **map)
{
	int	player_x;
	int	player_y;

	player_x = 0;
	player_y = 0;
	while (!ft_strchr(map[player_y], 'P'))
		player_y++;
	while (map[player_y][player_x] != 'P')
		player_x++;
	flood_fill(map, player_x, player_y);
}
