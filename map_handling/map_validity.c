/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:28:18 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/30 16:27:43 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <fcntl.h>

int	one_exit(char **map)
{
	int e;
	
	e = 0;
	while ()
	{
		if ( == 'E')
			e++;
		if (e > 1)
			return (0);
	}
	return (e) // (either 0 or 1)
}

int	one_player(char **map)
{
	int p;
	
	p = 0;
	while ()
	{
		if ( == 'P')
			p++;
		if (p > 1)
			return (0);
	}
	return (p) // (either 0 or 1)
}

int	collectives(char **map)
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
	return (c) // (either 0 or more)
}

int	rectangular(char **map)
{
	
}
int	valid_map(const char **map)
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