/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_n_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:39:15 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/12 10:39:24 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

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

void	terminate_free(t_solong *solong, int error, char *message)
{
	int	moves;

	moves = solong->moves;
	if (solong->map)
		free_map(solong->map);
	delete_images(solong);
	if (solong->mlx)
		mlx_terminate(solong->mlx);
	if (error && message)
	{
		ft_printf("%s", message);
		exit(EXIT_FAILURE);
	}
	else if (message)
	{
		ft_printf("%sTotal moves: %d\n", message, moves);
		exit(EXIT_SUCCESS);
	}
}
