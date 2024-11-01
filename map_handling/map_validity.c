/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:28:18 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/01 15:56:30 by sniemela         ###   ########.fr       */
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
		if (map[i][j] == 'E')
			e++;
		if (e > 1)
			return (0);
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
		if (map[i][j] == 'P')
			p++;
		if (p > 1)
			return (0);
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

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		i++;
		if (len != (int)ft_strlen(map[i]))
			return (0);
	}
	if (i < 3) // height too short;
		return (0);
	return (1);
}

int	valid_map(char **map)
{
	if (!rectangular(map))
		return (0);
	if (!collectives(map))
		return (0);
	if (!one_player(map))
		return (0);
	if (!one_exit(map))
		return (0);
	return (1);
}