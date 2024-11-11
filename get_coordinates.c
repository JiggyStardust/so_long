/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:01:23 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/11 12:02:44 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_player_x(char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x] != '\0')
	{
		if (map[y][x] == 'P')
			break ;
		x++;
	}
	return (x);
}

int	get_player_y(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		if (ft_strchr(map[y], 'P'))
			break ;
		y++;
	}
	return (y);
}

int	get_exit_x(char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x] != '\0')
	{
		if (map[y][x] == 'E')
			break ;
		x++;
	}
	return (x);
}

int	get_exit_y(char **map)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		if (ft_strchr(map[y], 'E'))
			break ;
		y++;
	}
	return (y);
}
