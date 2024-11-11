/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:35:20 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/11 12:05:20 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	draw_floor_n_exit(t_solong *solong)
{
	int	x;
	int	y;

	y = 0;
	while (solong->map[y] != NULL)
	{
		x = 0;
		while (solong->map[y][x] != '\0')
		{
			if (mlx_image_to_window(solong->mlx, solong->f_img,
					x * TILE, y * TILE) == -1)
				return (false);
			if (solong->map[y][x] == 'E')
			{
				if (mlx_image_to_window(solong->mlx, solong->e_img,
						x * TILE, y * TILE) == -1)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

static bool	draw_wpc(t_solong *solong, char c, int x, int y)
{
	mlx_image_t	*image;

	if (c == '1')
		image = solong->w_img;
	else if (c == 'C')
		image = solong->c_img;
	else if (c == 'P')
		image = solong->p_img;
	else
		return (true);
	if (mlx_image_to_window(solong->mlx, image, x * TILE, y * TILE) == -1)
		return (false);
	return (true);
}

bool	images_to_window(t_solong *solong)
{
	int	x;
	int	y;

	y = 0;
	if (!draw_floor_n_exit(solong))
		return (false);
	while (solong->map[y] != NULL)
	{
		x = 0;
		while (solong->map[y][x] != '\0')
		{
			if (!draw_wpc(solong, solong->map[y][x], x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
