/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:25:59 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/15 15:16:40 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_empty_map(char **map)
{
	if (map[0][0])
	{
		return (TRUE);
	}
	else
		ft_printf(MAP_EMPTY_ERROR);
	return (FALSE);
}

int	is_rect_map(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (FALSE);
		else
			i++;
	}
	return (TRUE);
}

int	is_wrong_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == EXIT || map[i][j] == PLAYER_START
					|| map[i][j] == WALL || map[i][j] == FLOOR
					|| (map[i][j] == COLLECTIBLE)))
				return (FALSE);
			else
				j++;
		}
		i++;
	}
	return (TRUE);
}

int	check_walls(char **map)
{
	size_t	i;
	size_t	j;
	size_t	line;

	line = 0;
	while (map[line])
		line++;
	i = 0;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[line - 1][i] != '1')
			return (FALSE);
		i++;
	}
	j = 0;
	while (i < (line - 1))
	{
		if (map[j][0] != '1' || map[ft_strlen(map[0])][0] != '1')
			return (FALSE);
		j++;
	}
	return (TRUE);
}

int	ft_check_map(char **map)
{
	if (is_empty_map(map) == FALSE)
		return (ft_printf(MAP_EMPTY_ERROR), 1);
	if (is_rect_map(map) == FALSE)
		return (ft_printf(MAP_RECT_ERROR), 1);
	if (is_wrong_map(map) == FALSE)
		return (ft_printf(MAP_WRONG_COMP), 1);
	if (min_tiles(map) == FALSE)
		return (ft_printf(MIN_TILES_ERROR), 1);
	if (check_walls(map) == FALSE)
		return (ft_printf(MAP_WALLS_ERROR), 1);
	return (TRUE);
}
