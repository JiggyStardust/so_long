/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:34:24 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/07 15:45:09 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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


/**
 * Generic loop hook for any custom hooks to add to the main loop. 
 * Executes a function per frame, so be careful.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] f The function.
 * @param[in] param The parameter to pass on to the function.
 * @returns Whether or not the hook was added successfully. 
 */
//bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param);



/**
 * Initializes the rendering of MLX, this function won't return until
 * mlx_close_window is called, meaning it will loop until the user requests that
 * the window should close.
 * 
 * @param[in] mlx The MLX instance handle.
 */
///void mlx_loop(mlx_t* mlx);



/**
 * Notifies MLX that it should stop rendering and exit the main loop.
 * This is not the same as terminate, this simply tells MLX to close the window.
 * 
 * @param[in] mlx The MLX instance handle.
 */
//void mlx_close_window(mlx_t* mlx);



/**
 * This function sets the close callback, which is called in attempt to close 
 * the window device such as a close window widget used in the window bar.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The close callback function.
 * @param[in] param An additional optional parameter.
 */
//void mlx_close_hook(mlx_t* mlx, mlx_closefunc func, void* param);

bool	draw_floor_n_exit(t_solong *solong)
{
	int	x;
	int	y;

	y = 0;
	while (solong->map[y] != NULL)
	{
		x = 0;
		while (solong->map[y][x] != '\0')
		{
			if (mlx_image_to_window(solong->mlx, solong->f_img, x * TILE_SIZE, y * TILE_SIZE) == -1)
				return (false);
			if (solong->map[y][x] == 'E')
			{
				if (mlx_image_to_window(solong->mlx, solong->e_img, x * TILE_SIZE, y * TILE_SIZE) == -1)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	draw_wpc(t_solong *solong, char c, int x, int y)
{
	mlx_image_t *image;
	if (c == '1')
		image = solong->w_img;
	else if (c == 'C')
		image = solong->c_img;
	else if (c == 'P')
		image = solong->p_img;
	else
		return (true);
	if (mlx_image_to_window(solong->mlx, image, x * TILE_SIZE, y * TILE_SIZE) == -1)
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

void	close_window(void *param)
{
	t_solong	*solong;
	
	solong = (t_solong *)param;
	terminate_free(solong, 0, NULL);
	exit(0);
}
bool	valid_move(t_solong *solong, int x, int y)
{
	if (solong->map[y][x] == '1')
		return (false);
	else
		return (true);
}

bool	move_player(t_solong *solong, int x, int y)
{
	int	x_new;
	int	y_new;

	x_new = solong->player_x + x;
	y_new = solong->player_y + y;
	if !(valid_move(solong, x_new, y_new))
		return (false);
	if (solong->map[y_new][x_new] == 'C')
	{
		solong->collectibles--;
		solong->map[y_new][x_new] = '0';
	}
	if (solong->map[solong->player_x][solong->player_y] == 'E') // 'E' pos should be stored in struct for this check, add later, this doesn't work
		solong->map[solong->player_x][solong->player_y] = 'E';
	else
		solong->map[solong->player_x][solong->player_y] = '0';
// THIS IS TOTALLY UNFINISHED, NEEDED TO LEAVE HOME EARLY :)
// TO BE CONT. ON FRI 8/11

}

void	key_hook(void *param)
{
	t_solong	*solong;
	int			x;
	int			y;
	
	x = 0;
	y = 0;
	solong = (t_solong *)param;
	if (mlx_is_key_down(solong->mlx, MLX_KEY_UP) ||
		mlx_is_key_down(solong->mlx, MLX_KEY_W))
		y--;
	else if (mlx_is_key_down(solong->mlx, MLX_KEY_DOWN) ||
		mlx_is_key_down(solong->mlx, MLX_KEY_S))
		y++;
	else if (mlx_is_key_down(solong->mlx, MLX_KEY_LEFT) ||
		mlx_is_key_down(solong->mlx, MLX_KEY_A))
		x--;
	else if (mlx_is_key_down(solong->mlx, MLX_KEY_RIGHT) ||
		mlx_is_key_down(solong->mlx, MLX_KEY_D))
		x++;
	else if (mlx_is_key_down(solong->mlx, MLX_KEY_ESCAPE))
		terminate_free(solong, 0, "You chose to quit the game\n");
	if (!move_player(solong, x, y))
		return ;
}

int main(int ac, char **av)
{
	t_solong	solong;

	if (ac != 2)
		return (0);
	if (!init_solong(&solong, av[1], TILE_SIZE))
		terminate_free(&solong, 1, "Error\nCannot initialize the game.\n");
	if (!setup_textures(&solong))
		terminate_free(&solong, 1, "Error\nProblem with loading textures.\n");
	if (!setup_images(&solong))
		terminate_free(&solong, 1, "Error\nProblem with converting textures to images.\n");
	if (!images_to_window(&solong))
		terminate_free(&solong, 1, "Error\nProblem with opening the window.\n");
	mlx_loop_hook(solong.mlx, key_hook, &solong);
	mlx_close_hook(solong.mlx, close_window, &solong);
	mlx_loop(solong.mlx);
	return (0);
}
