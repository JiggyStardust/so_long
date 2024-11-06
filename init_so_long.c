/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:41:03 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/06 10:35:31 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_width(char **map, int tile)
{
	int	width;

	width = (int)ft_strlen(map[0]) * tile;
	return (width);
}

int	get_height(char **map, int tile)
{
	int	i;
	int	height;

	i = 0;
	while (map[i] != NULL)
		i++;
	height = i * tile;
	return (height);
}

int		get_player_x(char **map, int y)
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
int		get_player_y(char **map)
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

void	start_init(t_solong *solong)
{
	solong->mlx = NULL;
	solong->p_text = NULL;
	solong->f_text = NULL;
	solong->w_text = NULL;
	solong->e_text = NULL;
	solong->c_text = NULL;
	solong->p_img = NULL;
	solong->f_img = NULL;
	solong->w_img = NULL;
	solong->c_img = NULL;
	solong->e_img = NULL;
	solong->map = NULL;
	solong->width = 0;
	solong->height = 0;
	solong->player_x = 0;
	solong->player_y = 0;
	solong->collectibles = 0;
	solong->game_over = false;
}

bool	init_solong(t_solong *solong, char *path_to_map, int tile_size)
{
	start_init(solong);
	if (!(solong->map = create_map(path_to_map)))
		return (false);
	if (!valid_map(solong->map) || !playable_map(solong->map))
		return (false);
	solong->width = get_width(solong->map, tile_size);
	solong->height = get_height(solong->map, tile_size);
	if (!(solong->mlx = mlx_init(solong->width, solong->height, "so_long", true)))
		return (false);
	solong->player_y = get_player_y(solong->map);
	solong->player_x = get_player_x(solong->map, solong->player_y);
	return (true);
}
