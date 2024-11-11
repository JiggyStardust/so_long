/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:34:24 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/11 12:05:41 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	close_window(void *param)
{
	t_solong	*solong;

	solong = (t_solong *)param;
	terminate_free(solong, 0, NULL);
	exit(0);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_solong	*solong;
	int			x;
	int			y;

	x = 0;
	y = 0;
	solong = (t_solong *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			y = -1;
		else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			y = 1;
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			x = -1;
		else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			x = 1;
		else if (keydata.key == MLX_KEY_ESCAPE)
			terminate_free(solong, 0, "Game ended\n");
		if ((x != 0 || y != 0) && !move_player(solong, x, y))
			return ;
	}
}

int	main(int ac, char **av)
{
	t_solong	solong;

	if (ac != 2)
		return (0);
	if (!init_solong(&solong, av[1], TILE))
		terminate_free(&solong, 1, "Error\nCannot initialize the game.\n");
	if (!setup_textures(&solong))
		terminate_free(&solong, 1, "Error\nProblem with loading textures.\n");
	if (!setup_images(&solong))
		terminate_free(&solong, 1, "Error\nCant convert textures to images.\n");
	if (!images_to_window(&solong))
		terminate_free(&solong, 1, "Error\nProblem with opening the window.\n");
	mlx_key_hook(solong.mlx, key_hook, &solong);
	mlx_close_hook(solong.mlx, close_window, &solong);
	mlx_loop(solong.mlx);
	return (0);
}
