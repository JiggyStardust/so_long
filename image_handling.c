/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:31:46 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/11 11:36:43 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	setup_textures(t_solong *solong)
{
	solong->p_text = mlx_load_png("./images/player.png");
	if (!solong->p_text)
		return (false);
	solong->f_text = mlx_load_png("./images/floor.png");
	if (!solong->f_text)
		return (false);
	solong->w_text = mlx_load_png("./images/wall.png");
	if (!solong->w_text)
		return (false);
	solong->c_text = mlx_load_png("./images/collectable.png");
	if (!solong->c_text)
		return (false);
	solong->e_text = mlx_load_png("./images/exit.png");
	if (!solong->e_text)
		return (false);
	return (true);
}

bool	setup_images(t_solong *solong)
{
	solong->p_img = mlx_texture_to_image(solong->mlx, solong->p_text);
	if (!solong->p_img)
		return (false);
	solong->f_img = mlx_texture_to_image(solong->mlx, solong->f_text);
	if (!solong->f_img)
		return (false);
	solong->w_img = mlx_texture_to_image(solong->mlx, solong->w_text);
	if (!solong->w_img)
		return (false);
	solong->c_img = mlx_texture_to_image(solong->mlx, solong->c_text);
	if (!solong->c_img)
		return (false);
	solong->e_img = mlx_texture_to_image(solong->mlx, solong->e_text);
	if (!solong->e_img)
		return (false);
	return (true);
}
