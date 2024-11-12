/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:41:03 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/12 15:52:35 by sniemela         ###   ########.fr       */
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

void	start_init(t_solong *solong)
{
	solong->mlx = NULL;
	solong->p_img = NULL;
	solong->f_img = NULL;
	solong->w_img = NULL;
	solong->c_img = NULL;
	solong->e_img = NULL;
	solong->map = NULL;
	solong->width = 0;
	solong->height = 0;
	solong->p_x = 0;
	solong->p_y = 0;
	solong->e_x = 0;
	solong->e_y = 0;
	solong->coll = 0;
	solong->moves = 0;
	solong->can_exit = false;
}

bool	init_solong(t_solong *solong, char *path_to_map)
{
	start_init(solong);
	solong->map = create_map(path_to_map);
	if (!solong->map || !solong->map[0])
	{
		ft_printf("Error\nMap creation incomplete.\n");
		return (false);
	}
	if (!valid_map(solong) || !playable_map(solong->map))
		return (false);
	solong->width = get_width(solong->map, TILE);
	solong->height = get_height(solong->map, TILE);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	solong->mlx = mlx_init(solong->width, solong->height, "🐷+🍕=❤️‍🔥", true);
	if (!solong->mlx)
		return (false);
	solong->p_y = get_player_y(solong->map);
	solong->p_x = get_player_x(solong->map, solong->p_y);
	solong->e_y = get_exit_y(solong->map);
	solong->e_x = get_exit_x(solong->map, solong->e_y);
	return (true);
}
