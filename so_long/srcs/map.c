/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:14:42 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/03/28 17:07:49 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_free_map(char **map)
{
    int i;
    
    i = -1;
    while (map[++i])
        free(map[i]);
    free(map);
}

void    get_map_size(t_solong *game, char **map)
{
    int i;
    
    i = 0;
    game->n_c = total_collectibles(game);
    game->map_w = ft_strlen(map[0]) * 32;
    while (map[i])
        i++;
    game->map_h = i * 32;
}

int ft_file_extension(const char *filename)
{
    size_t i;
    
    i = ft_strlen(filename) - 1;
    if (filename[i] != 'r' || filename[i - 1] != 'e' || filename[i - 2] != 'b'
            || filename[i -3] != '.')
            return (FALSE);
    return (TRUE);
}

char    **read_map(char *map_file)
{
    int     fd;
    char    *map_temp;
    char    **map;
    int     n;

    n = 0;
    map_temp = ft_calloc(BFF_SIZE + 1, sizeof(char));
    if (!map_temp)
        return (0);
    fd = open(map_file, O_RDONLY);
    if (fd < 0)
    {
        free(map_temp);
        return (0);
    }
    n = read(fd, map_temp, BFF_SIZE);
    if (n == -1 || n == 0)
    {
        free(map_temp);
        return (0);
    }
    map = ft_split(map_temp, '\n');
    free(map_temp);
    close(fd);
    return (map);
}
