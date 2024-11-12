/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:31:46 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/12 10:40:18 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*png_to_resized_img(t_solong *solong, const char *path_text)
{
	mlx_texture_t	*text;
	mlx_image_t		*img;

	text = mlx_load_png(path_text);
	if (!text)
		return (NULL);
	img = mlx_texture_to_image(solong->mlx, text);
	if (!img)
	{
		mlx_delete_texture(text);
		return (NULL);
	}
	mlx_delete_texture(text);
	if (img->width != TILE || img->height != TILE)
	{
		if (!mlx_resize_image(img, TILE, TILE))
		{
			mlx_delete_image(solong->mlx, img);
			return (NULL);
		}
	}	
	return (img);
}

bool	setup_images(t_solong *solong)
{
	solong->p_img = png_to_resized_img(solong, "./textures/player.png");
	if (!solong->p_img)
		return (false);
	solong->f_img = png_to_resized_img(solong, "./textures/floor.png");
	if (!solong->f_img)
		return (false);
	solong->w_img = png_to_resized_img(solong, "./textures/wall.png");
	if (!solong->w_img)
		return (false);
	solong->c_img = png_to_resized_img(solong, "./textures/collectible.png");
	if (!solong->c_img)
		return (false);
	solong->e_img = png_to_resized_img(solong, "./textures/exit.png");
	if (!solong->e_img)
		return (false);
	return (true);
}
