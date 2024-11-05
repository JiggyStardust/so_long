/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:34:24 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/05 16:38:54 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// static mlx_image_t* image;

// // -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

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

bool setup_textures(t_solong *solong)
{
	solong->p_text = mlx_load_png("images/player.png");
	if (!solong->p_text)
		return (false);
	solong->f_text = mlx_load_png("images/floor.png");
	if(!solong->f_text)
		return (false);
	solong->w_text = mlx_load_png("images/wall.png");
	if(!solong->w_text)
		return (false);
	solong->c_text = mlx_load_png("images/collectible.png");
	if (!solong->c_text)
		return (false);
	solong->e_text = mlx_load_png("images/exit.png");
	if (!solong->e_text)
		return (false);
	return (true);
}

bool setup_images(t_solong *solong)
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
	solong->c_img = mlx_texture_to_image(solong->mlx, solong->c_text);
	if (!solong->c_img)
		return (false);
	return (true);
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

void	terminate_free(t_solong *solong, int error, char *message)
{
	if (solong->map)
		free_map(solong->map);
	delete_textures(solong);
	delete_images(solong);
	if (solong->mlx)
		mlx_terminate(solong->mlx);
	if (error)
	{
		perror(message);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
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

static bool	init_solong(t_solong *solong, char *path_to_map, int tile_size)
{
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

// int main(int ac, char **av)
// {
// 	t_solong	solong;

// 	if (ac != 2)
// 		return (0);
// 	solong.map = create_map(av[1]);
// 	if (!solong.map)
// 		return (1);
// 	if (!valid_map(solong.map) || !playable_map(solong.map))
// 	{
// 		free_map(solong.map);
// 		return(0);
// 	}
// 	solong.width = get_width(solong.map, TILE_SIZE);
// 	solong.height = get_height(solong.map, TILE_SIZE);
// 	if (!(solong.mlx = mlx_init(solong.width, solong.height, "so_long", true)))
// 	{
// 		free_map(solong.map);
// 		return (1);
// 	}
// 	if !(setup_images(&solong));
// 		terminate_free(&solong, 1, "Error\nProblem with loading images.");
// 	terminate_free(&solong);
// 	return (0);
// }

int main(int ac, char **av)
{
	t_solong	solong;

	if (ac != 2)
		return (0);
	if (!init_solong(&solong, av[1], TILE_SIZE))
		terminate_free(&solong, 1, "Error\nCannot initialize the game.");
	if (!setup_textures(&solong))
		terminate_free(&solong, 1, "Error\nProblem with loading textures.");
	if (!setup_images(&solong))
		terminate_free(&solong, 1, "Error\nProblem with converting textures to images.");
	terminate_free(&solong, 0, '\0');
	return (0);
}
