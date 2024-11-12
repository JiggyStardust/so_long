/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:27:17 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/12 13:30:40 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	vertical_walls(char **map, int last)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][last] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	horizontal_walls(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1')
			return (false);
		j++;
	}
	i = 0;
	while (map[i] != NULL)
		i++;
	i--;
	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
			return (false);
		j++;
	}
	return (true);
}

bool	closed_walls(char **map)
{
	int	last;

	last = ft_strlen(map[0]) - 1;
	if (!vertical_walls(map, last) || !horizontal_walls(map))
	{
		ft_printf("Error\nMap's walls should be closed.\n");
		return (false);
	}
	return (true);
}

bool	legit_symbols(char	**map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C')
			{
				ft_printf("Error\nMap contains forbidden symbols.\n");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
