/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_n_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:39:15 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/11 09:44:08 by sniemela         ###   ########.fr       */
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

void	terminate_free(t_solong *solong, int error, char *message)
{
	int	moves;

	moves = solong->moves;
	if (solong->map)
		free_map(solong->map);
	delete_textures(solong);
	delete_images(solong);
	if (solong->mlx)
		mlx_terminate(solong->mlx);
	if (error && message)
	{
		perror(message);
		exit(EXIT_FAILURE);
	}
	else if (message)
	{
		ft_printf("%sTotal moves: %d", message, moves);
		exit(EXIT_SUCCESS);
	}
}
