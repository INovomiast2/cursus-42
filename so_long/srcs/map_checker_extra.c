/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:40:09 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/01 10:22:58 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int min_tiles(char **map)
{
    int i;
    int j;
    int num_exit_char;
    int n_collectibles;
    
    i = 0;
    num_exit_char = 0;
    n_collectibles = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == EXIT || map[i][j] == PLAYER_START)
                num_exit_char++;
            if (map[i][j] == COLLECTIBLE)
                n_collectibles++;
            j++;
        }
        i++;
    }

    if (num_exit_char != 2 || n_collectibles < 1)
        return (FALSE);
    return (TRUE);
}

int *player_start_pos(char **map)
{
    int x;
    int y;
    int *position;

    position = (int *)ft_calloc(2, sizeof(int));
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == PLAYER_START)
            {
                position[0] = y;
                position[1] = x;
            }
            x++;
        }
        y++;
    }
    return (position);
}

void    flood_map(t_solong *game, int x, int y)
{
    if (!(x < 1 || y < 1 || x >= game->map_w || y > game->map_h
            || game->second_map[y][x] == '1' || game->second_map[y][x] == 'X'))
    {
        game->second_map[y][x] = 'X';
        flood_map(game, x + 1, y);
        flood_map(game, x - 1, y);
        flood_map(game, x, y + 1);
        flood_map(game, x, y - 1);
    }
}

int check_flood(char **map)
{
    int i;
    int j;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (!(map[i][j] == WALL || map[i][j] == FLOOR
                    || map[i][j] == 'X'))
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

int is_valid_path(t_solong *game, char *fd)
{
    int *position;

    game->second_map = read_map(fd);
    position = player_start_pos(game->second_map);
    flood_map(game, position[0], position[1]);
    if (check_flood(game->second_map) == FALSE)
    {
        free(position);
        ft_free_map(game->second_map);
        return (ft_printf(INVALID_PATH_ERROR), FALSE);
    }
    free(position);
    ft_free_map(game->second_map);
    return (TRUE);
}