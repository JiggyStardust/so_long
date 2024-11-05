/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:36:09 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/05 16:28:10 by sniemela         ###   ########.fr       */
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
	bool			game_over;
}	t_solong;

char	**create_map(char *path_to_map);
int		valid_map(char **map);
void	free_map(char **array);
int		playable_map(char **map);
void	flood_the_map(char **map);

#endif