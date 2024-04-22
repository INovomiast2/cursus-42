/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:14:42 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/22 11:51:51 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	get_map_size(t_solong *g, char **map)
{
	int	i;

	i = 0;
	g->n_c = total_coins(g);
	g->map_w = ft_strlen(map[0]) * 32;
	while (map[i])
		i++;
	g->map_h = i * 32;
}

int	ft_file_extension(const char *filename)
{
	size_t	i;

	i = ft_strlen(filename) - 1;
	if (filename[i] != 'r' || filename[i - 1] != 'e' || filename[i - 2] != 'b'
		|| filename[i - 3] != '.')
		return (FALSE);
	return (TRUE);
}

char	**read_map(char *map_file)
{
	int		fd;
	char	*map_temp;
	char	**map;
	int		n;
	int		i;

	map_temp = ft_calloc(BFF_SIZE + 1, sizeof(char));
	if (!map_temp)
		return (0);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (free(map_temp), NULL);
	n = read(fd, map_temp, BFF_SIZE);
	if (n == -1 || n == 0)
		return (free(map_temp), NULL);
	map = ft_split(map_temp, '\n');
	i = 0;
	while (map && map[i])
	{
		if (map[i][ft_strlen(map[i]) - 1] == '0')
			return (ft_printf(MAP_WALLS_ERROR), ft_free_map(map), NULL);
		i++;
	}
	return (free(map_temp), close(fd), map);
}
