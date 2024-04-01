/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:26:35 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/01 12:25:00 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int total_collectibles(t_solong *game)
{
    int total;
    int i;
    int j;
    
    total = 0;
    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'C')
                total++;
            j++;
        }
        i++;
    }
    return (total);
}

void    ft_delete(t_solong *game)
{
    int i;
    int counter;
    
    i = 0;
    counter = game->n_c;
    while (i < counter)
    {
        if (((game->imgs->collectible->instances[i].y 
                        == game->imgs->character->instances->y)
                        && (game->imgs->collectible->instances[i].x
                        == game->imgs->character->instances->x))
                        && game->imgs->collectible->instances[i].enabled == true)
        {
            counter--;
            game->imgs->collectible->instances[i].enabled = false;
            return ;
        }
        i++;
    }
}

void    ft_exit(t_solong *game)
{
    if (game->imgs->exit->instances->enabled == false 
        && game->imgs->exit->instances->x / 32 == game->imgs->character->instances->x / 32
        && game->imgs->exit->instances->y / 32 == game->imgs->character->instances->y / 32)
    {
        ft_printf("Has ganado el juego con %i movimientos!\n", game->moves);
        mlx_close_window(game->mlx);
    }
}

void    ft_collect(t_solong *game)
{
    int i = 0;
    int counter = game->n_c;
    while (i < counter)
    {
        if (((game->imgs->collectible->instances[i].y / 32 
                        == game->imgs->character->instances->y / 32)
                        && (game->imgs->collectible->instances[i].x / 32
                        == game->imgs->character->instances->x / 32))
                        && game->imgs->collectible->instances[i].enabled == true)
        {
            counter--;
            game->imgs->collectible->instances[i].enabled = false;
            game->map[game->imgs->character->instances->y / 32]
            [game->imgs->character->instances->x / 32] = FLOOR;
            game->c_counter++;
            if (game->c_counter == game->n_c)
                game->imgs->exit->instances->enabled = false; 
            return ;
        }
        i++;
    }
}
