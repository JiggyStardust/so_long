/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:28:18 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/04 14:48:07 by sniemela         ###   ########.fr       */
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
				return (0);
			j++;
		}
		i++;
	}
	return (e); // (either 0 or 1)
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
				return (0);
			j++;
		}
		i++;
	}
	return (p); // (either 0 or 1)
}

static int	collectives(char **map)
{
	int c;
	int	i;
	int	j;
	
	i = 0;
	c = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j++] != '\0')
		{
			if (map[i][j] == 'C')
				c++;
		}
		i++;
	}
	return (c); // (either 0 or more)
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
			return (0);
		i++;
	}
	if (i < 3)
		return (0);
	return (1);
}

int	valid_map(char **map)
{
	int ret;
	
	ret = 1;
	if (!rectangular(map))
	{
		ft_printf("Map isn't rectangular or it's too short!\n");
		ret = 0;
	}
	if (!collectives(map))
	{
		ft_printf("Not enough collectives!\n");
		ret = 0;
	}
	if (!one_player(map))
	{
		ft_printf("We should have (only) one player on the map!\n");
		ret = 0;
	}
	if (!one_exit(map))
	{
		ft_printf("Map should have (only) one exit!\n");
		ret = 0;
	}
	return (ret);
}
