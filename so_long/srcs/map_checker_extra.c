/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:40:09 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/22 11:55:31 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	min_tiles(char **map)
{
	int	i;
	int	j;
	int	num_exit_char;
	int	n_collectibles;

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

int	*player_start_pos(char **map)
{
	int	x;
	int	y;
	int	*position;

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

void	flood_map(t_solong *g, int x, int y)
{
	if (x < 0 || y < 0 || x >= g->map_w || y >= g->map_h)
		return ;
	if (g->second_map[y][x] == '1' || g->second_map[y][x] == 'X')
		return ;
	g->second_map[y][x] = 'X';
	flood_map(g, x + 1, y);
	flood_map(g, x - 1, y);
	flood_map(g, x, y + 1);
	flood_map(g, x, y - 1);
}

int	check_flood(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == WALL || map[i][j] == FLOOR || map[i][j] == 'X'))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	is_valid_path(t_solong *g, char *fd)
{
	int	*position;

	g->second_map = read_map(fd);
	position = player_start_pos(g->second_map);
	flood_map(g, position[0], position[1]);
	if (check_flood(g->second_map) == FALSE)
	{
		free(position);
		ft_free_map(g->second_map);
		return (ft_printf(INVALID_PATH_ERROR), FALSE);
	}
	free(position);
	ft_free_map(g->second_map);
	return (TRUE);
}
