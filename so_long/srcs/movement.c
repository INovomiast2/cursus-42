/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:44:20 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/01 12:24:22 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_move_up(t_solong *game)
{
    if (game->map[game->imgs->character->instances->y / 32 - 1]
            [game->imgs->character->instances->x / 32] != WALL)
    {
        game->imgs->character->instances->y -= MOVE;
        game->moves++;
        ft_printf("Move: %i\n", game->moves);
    }
}

void    ft_move_down(t_solong *game)
{
    if (game->map[game->imgs->character->instances->y / 32 + 1]
            [game->imgs->character->instances->x / 32] != WALL)
    {
        game->imgs->character->instances->y += MOVE;
        game->moves++;
        ft_printf("Move: %i\n", game->moves);
    }
}

void    ft_move_left(t_solong *game)
{
    if (game->map[game->imgs->character->instances->y / 32]
            [game->imgs->character->instances->x / 32 - 1] != WALL)
    {
        game->imgs->character->instances->x -= MOVE;
        game->moves++;
        ft_printf("Move: %i\n", game->moves);
    }
}

void    ft_move_right(t_solong *game)
{
    if (game->map[game->imgs->character->instances->y / 32]
            [game->imgs->character->instances->x / 32 + 1] != WALL)
    {
        game->imgs->character->instances->x += MOVE;
        game->moves++;
        ft_printf("Moves: %i\n", game->moves);
    }
}

void    ft_key(mlx_key_data_t keydata, void *param)
{
    t_solong *game;
    
    game = param;
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
        ft_move_up(game);
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
        ft_move_down(game);
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
        ft_move_left(game);
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
        ft_move_right(game);
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
    {
        mlx_close_window(game->mlx);
        ft_printf("\n😔\033[31m-[CERRASTE EL JUEGO]-\033[0m😔");
        return ;
    }
    ft_collect(game);
    ft_exit(game);
}
