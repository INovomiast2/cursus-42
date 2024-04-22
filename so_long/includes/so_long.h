/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:05:44 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/15 13:04:55 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <memory.h>
# include <stdint.h>
# include <fcntl.h>

# define EXIT 'E'
# define PLAYER_START 'P'
# define COLLECTIBLE 'C'
# define WALL '1'
# define FLOOR '0'

# define ERROR "\033"
# define PARAMS_ERROR "PARAMS: Only 2 are accepted.\n"
# define MAP_EXT_ERROR "EXTENSION: Only Allowed\033[1m .ber \033[0m\n"
# define MAP_EMPTY_ERROR "MAP: Turned empty!\n"
# define MAP_RECT_ERROR "MAP: Is not a rectangle!\n"
# define MAP_WRONG_COMP "MAP: Wrong Components!\n"
# define MAP_WALLS_ERROR "MAP: No walls around it!\n"
# define MIN_TILES_ERROR "COMP: You don't have the correct components!\n"
# define INVALID_PATH_ERROR "PATHS: Not valid!\n"

# define BFF_SIZE 10000
# define FALSE 1
# define TRUE 0
# define MOVE 32

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*coin;
	mlx_texture_t	*plyr;
	mlx_texture_t	*e_close;
	mlx_texture_t	*e_open;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*coin;
	mlx_image_t	*plyr;
	mlx_image_t	*exit;
	mlx_image_t	*second_exit;
}	t_images;

typedef struct s_slong
{
	struct s_textures	*txtrs;
	struct s_images		*imgs;
	mlx_t				*mlx;
	char				**map;
	char				**second_map;
	int					map_w;
	int					map_h;
	int					c_counter;
	int					moves;
	int					n_c;
}	t_solong;

// Starts th
int		init_so_long(t_solong *g);
int		ft_file_extension(const char *filename);
char	**read_map(char *map);
void	draw_map(t_solong *g, t_images *images);
int		ft_check_map(char **map);
int		is_empty_map(char **map);
int		is_rect_map(char **map);
int		is_wrong_map(char **map);
int		check_walls(char **map);
void	get_map_size(t_solong *g, char **map);
int		is_valid_path(t_solong *g, char *fd);
int		*player_start_pos(char **map);
void	flood_map(t_solong *g, int x, int y);
int		check_flood(char **map);
int		total_coins(t_solong *g);
void	ft_free_map(char **map);
int		min_tiles(char **map);
void	ft_get_textures(t_solong *g);
void	ft_get_images(t_solong *g);
void	ft_key(mlx_key_data_t keydata, void *param);
void	ft_move_up(t_solong *g);
void	ft_move_down(t_solong *g);
void	ft_move_left(t_solong *g);
void	ft_move_right(t_solong *g);
void	ft_collect(t_solong *g);
void	ft_delete(t_solong *g);
void	ft_exit(t_solong *g);

#endif