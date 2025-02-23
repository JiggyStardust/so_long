/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:09:51 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/11 11:30:53 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	exit_reachable(char **map_flooded)
{
	int		i;

	i = 0;
	while (map_flooded[i] != NULL)
	{
		if (ft_strchr(map_flooded[i], 'E'))
			return (0);
		i++;
	}
	return (1);
}

static int	collectives_reachable(char **map_flooded)
{
	int		i;

	i = 0;
	while (map_flooded[i] != NULL)
	{
		if (ft_strchr(map_flooded[i], 'C'))
			return (0);
		i++;
	}
	return (1);
}

static char	**copy_map(char **src)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != NULL)
		i++;
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (NULL);
	while (src[j] != NULL)
	{
		dest[j] = ft_strdup(src[j]);
		if (!dest[j])
		{
			while (--j >= 0)
				free(dest[j]);
			return (NULL);
		}
		j++;
	}
	dest[j] = NULL;
	return (dest);
}

int	playable_map(char **map)
{
	char	**map_copy;
	int		ret;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	flood_the_map(map_copy);
	ret = 1;
	if (!collectives_reachable(map_copy))
	{
		ft_printf("Error\nAll the collectibles aren't reachable!\n");
		ret = 0;
	}
	if (!exit_reachable(map_copy))
	{
		ft_printf("Error\nThe exit isn't reachable, can't win!\n");
		ret = 0;
	}
	free_map(map_copy);
	return (ret);
}
