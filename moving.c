/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:30:21 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/11 14:01:52 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	valid_move(t_solong *solong, int x, int y)
{
	if (solong->map[y][x] == '1')
		return (false);
	else
	{
		solong->moves++;
		ft_printf("Moves: %d\n", solong->moves);
		return (true);
	}
}

static bool	handle_move_logic(t_solong *solong, int x_new, int y_new)
{
	if (!valid_move(solong, x_new, y_new))
		return (false);
	if (solong->map[y_new][x_new] == 'C')
		solong->coll--;
	if (solong->coll == 0)
		solong->can_exit = true;
	if (solong->can_exit && y_new == solong->e_y && x_new == solong->e_x)
		terminate_free(solong, 0, "\nCongraz, you won!🎂\n");
	return (true);
}

bool	move_player(t_solong *solong, int x, int y)
{
	int			x_new;
	int			y_new;
	mlx_image_t	*img;

	x_new = solong->p_x + x;
	y_new = solong->p_y + y;
	if (!handle_move_logic(solong, x_new, y_new))
		return (false);
	if (solong->p_y == solong->e_y && solong->p_x == solong->e_x)
		img = solong->e_img;
	else
		img = solong->f_img;
	if (mlx_image_to_window(solong->mlx, img,
			solong->p_x * TILE, solong->p_y * TILE) == -1)
		terminate_free(solong, 1, "Error\nCouldn't render image.\n");
	solong->map[y_new][x_new] = 'P';
	if (mlx_image_to_window(solong->mlx, solong->p_img,
			x_new * TILE, y_new * TILE) == -1)
		terminate_free(solong, 1, "Error\nCouldn't render image.\n");
	solong->p_x = x_new;
	solong->p_y = y_new;
	return (true);
}
