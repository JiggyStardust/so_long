/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:37:06 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/06 09:37:51 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	delete_images(t_solong *solong)
{
	if (solong->p_img)
		mlx_delete_image(solong->mlx, solong->p_img);
	if (solong->f_img)
		mlx_delete_image(solong->mlx, solong->f_img);
	if (solong->w_img)
		mlx_delete_image(solong->mlx, solong->w_img);
	if (solong->c_img)
		mlx_delete_image(solong->mlx, solong->c_img);
	if (solong->e_img)
		mlx_delete_image(solong->mlx, solong->e_img);
}

void	delete_textures(t_solong *solong)
{
	if (solong->p_text)
		mlx_delete_texture(solong->p_text);
	if (solong->f_text)
		mlx_delete_texture(solong->f_text);
	if (solong->w_text)
		mlx_delete_texture(solong->w_text);
	if (solong->c_text)
		mlx_delete_texture(solong->c_text);
	if (solong->e_text)
		mlx_delete_texture(solong->e_text);
}
