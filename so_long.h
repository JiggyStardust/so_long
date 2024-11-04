/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:36:09 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/04 14:44:41 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "MLX42/include/MLX42/MLX42_Int.h"

// # define WALL 1
// # define TEXT 0
// # define COIN 'C'
// # define PLAYER 'P'
// # define EXIT 'E'

char	**create_map(char *path_to_map);
int		valid_map(char **map);
void	free_map(char **array);
int		playable_map(char **map);
void	flood_the_map(char **map);

#endif