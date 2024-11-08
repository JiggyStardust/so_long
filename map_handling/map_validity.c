/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:28:18 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/08 12:20:15 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	one_exit(char **map)
{
	int e;
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
			if (e > 1)
			{
				ft_printf("Error\nThere's %d exits, while there should be only 1.", e);
				return (0);
			}
			j++;
		}
		i++;
	}
	if (e == 0)
		ft_printf("Error\nThere isn't an exit, tough luck...\n");
	return (e);
}

static int	one_player(char **map)
{
	int p;
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
			if (p > 1)
			{
				ft_printf("Error\nThere's %d players, while there should be only 1.\n", p);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (p);
}

static int	collectives(t_solong *solong)
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
				solong->collectibles++;
		}
		i++;
	}
	if (solong->collectibles < 1)
		ft_printf("Error\nNot enough collectibles!\n");
	return (solong->collectibles);
}

static int	rectangular(char **map)
{
	int	len;
	int	i;

	if (!map || !map[0])
		return (0);
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
	return (1);
}

int	valid_map(t_solong *solong)
{
	int ret;
	
	ret = 1;
	if (!rectangular(solong->map) || !collectives(solong) || !one_player(solong->map) ||
		!one_exit(solong->map))
		ret = 0;
	return (ret);
}