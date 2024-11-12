/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:28:18 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/12 15:43:11 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	one_exit(char **map)
{
	int	e;
	int	i;
	int	j;

	e = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (e == 0)
		ft_printf("Error\nThere isn't an exit, tough luck...\n");
	if (e > 1)
	{
		ft_printf("Error\nThere's %d exits instead of one.\n", e);
		return (0);
	}
	return (e);
}

static int	one_player(char **map)
{
	int	p;
	int	i;
	int	j;

	p = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (p > 1 || p == 0)
	{
		ft_printf("Error\nThere's %d players, instead of 1\n", p);
		return (0);
	}
	return (p);
}

static int	collectibles(t_solong *solong)
{
	int	i;
	int	j;

	i = 0;
	while (solong->map[i] != NULL)
	{
		j = 0;
		while (solong->map[i][j++] != '\0')
		{
			if (solong->map[i][j] == 'C')
				solong->coll++;
		}
		i++;
	}
	if (solong->coll < 1)
		ft_printf("Error\nNot enough collectibles!\n");
	return (solong->coll);
}

static int	rectangular(char **map)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (len != (int)ft_strlen(map[i]))
		{
			ft_printf("Error\nMap isn't rectangular.\n");
			return (0);
		}
		i++;
	}
	if (i < 3)
	{
		ft_printf("Error\nMap is too short.\n");
		return (0);
	}
	if (len < 3)
	{
		ft_printf("Error\nMap width is too small.");
		return (0);
	}
	return (1);
}

bool	valid_map(t_solong *solong)
{
	if (!rectangular(solong->map) || !collectibles(solong)
		|| !one_player(solong->map) || !one_exit(solong->map)
		|| !legit_symbols(solong->map) || !closed_walls(solong->map))
		return (false);
	return (true);
}
