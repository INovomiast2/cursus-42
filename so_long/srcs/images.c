/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:04:10 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/01 12:28:26 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_get_textures(t_solong *game)
{
    game->txtrs = ft_calloc(1, sizeof(t_textures));
    game->txtrs->floor = mlx_load_png("assets/textures/enviroment/grass/grass_env_texture.png");
    game->txtrs->wall = mlx_load_png("assets/textures/enviroment/obstacles/wall_obs_env_texture.png");
    game->txtrs->collectible = mlx_load_png("assets/textures/collectible/coin_state_normal.png");
    game->txtrs->character = mlx_load_png("assets/textures/character/char_sprite.png");
    game->txtrs->exit_closed = mlx_load_png("assets/textures/win/ext_closed.png");
    game->txtrs->exit_open = mlx_load_png("assets/textures/win/ext_open.png");
}

void    ft_get_images(t_solong *game)
{
    game->imgs = ft_calloc(1, sizeof(t_images));
    game->imgs->floor = mlx_texture_to_image(game->mlx, game->txtrs->floor);
    game->imgs->wall = mlx_texture_to_image(game->mlx, game->txtrs->wall);
    game->imgs->collectible = mlx_texture_to_image(game->mlx, game->txtrs->collectible);
    game->imgs->character = mlx_texture_to_image(game->mlx, game->txtrs->character);
    game->imgs->exit = mlx_texture_to_image(game->mlx, game->txtrs->exit_closed);
    game->imgs->second_exit = mlx_texture_to_image(game->mlx, game->txtrs->exit_open);
    mlx_delete_texture(game->txtrs->floor);
    mlx_delete_texture(game->txtrs->wall);
    mlx_delete_texture(game->txtrs->collectible);
    mlx_delete_texture(game->txtrs->character);
    mlx_delete_texture(game->txtrs->exit_closed);
    mlx_delete_texture(game->txtrs->exit_open);
}

void    ft_draw_floor(t_solong *game, t_images *image)
{
    int x;
    int y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            mlx_image_to_window(game->mlx, image->floor, x * 32, y * 32);
            if (game->map[y][x] == WALL)
                mlx_image_to_window(game->mlx, image->wall, x * 32, y * 32);
            if (game->map[y][x] == EXIT)
            {
                mlx_image_to_window(game->mlx, image->second_exit, x * 16, y * 16);
                mlx_image_to_window(game->mlx, image->exit, x * 16, y * 16);
            }
            x++;
        }
        y++;
    }
}

void    draw_map(t_solong *game, t_images *image)
{
    int x;
    int y;

    ft_draw_floor(game, image);
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == COLLECTIBLE)
                mlx_image_to_window(game->mlx, image->collectible, x * 16, y * 16);
            
            if (game->map[y][x] == PLAYER_START)
                mlx_image_to_window(game->mlx, image->character, x * 16, y * 16);
            x++;
        }
        y++;
    }
}