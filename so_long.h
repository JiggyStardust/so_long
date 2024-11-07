/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:36:09 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/07 12:09:51 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "MLX42/include/MLX42/MLX42_Int.h"
# include <stdbool.h>
# include <errno.h>

// # define WALL 1
// # define TEXT 0
// # define COIN 'C'
// # define PLAYER 'P'
// # define EXIT 'E'

# define TILE_SIZE 32

typedef struct s_solong
{
	mlx_t			*mlx;
	mlx_texture_t	*p_text;
	mlx_texture_t	*f_text;
	mlx_texture_t	*w_text;
	mlx_texture_t	*e_text;
	mlx_texture_t	*c_text;
	mlx_image_t		*p_img;
	mlx_image_t		*f_img;
	mlx_image_t		*w_img;
	mlx_image_t		*c_img;
	mlx_image_t		*e_img;
	char			**map;
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	int				collectibles;
	bool			can_exit;
}	t_solong;

// Map handling

char	**create_map(char *path_to_map);
void	flood_the_map(char **map);
int		playable_map(char **map);
int		valid_map(char **map);

// Setting up images
bool 	setup_images(t_solong *solong);
bool 	setup_textures(t_solong *solong);
bool 	images_to_window(t_solong *solong);

// freeing and deleting
void	delete_images(t_solong *solong);
void	delete_textures(t_solong *solong);
void	free_map(char **array);
void	terminate_free(t_solong *solong, int error, char *message);

// Initializing so_long
bool	init_solong(t_solong *solong, char *path_to_map, int tile_size);
int		get_player_x(char **map, int y);
int		get_player_y(char **map);
int		get_height(char **map, int tile);
int		get_width(char **map, int tile);

#endif