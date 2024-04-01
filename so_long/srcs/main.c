/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:05:34 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/01 11:06:27 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_so_long(t_solong *game)
{
	game->moves = 0;
	game->c_counter = 0;
	game->mlx = mlx_init(game->map_w, game->map_h, "So Long - Version 1.0.0", false);
	if (!(game->mlx))
		return (FALSE);
	ft_get_textures(game);
	ft_get_images(game);
	draw_map(game, game->imgs);
	mlx_key_hook(game->mlx, &ft_key, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_free_map(game->map);
	free(game->txtrs);
	free(game->imgs);
	return (0);
}

int	main(int ac, char **av)
{
	t_solong	game;

	if (ac != 2)
		return (ft_printf(PARAMS_ERROR), 1);
	if (ft_file_extension(av[1]) == FALSE)
		return (ft_printf(MAP_EXT_ERROR));
	game.map = read_map(av[1]);
	if (!game.map)
		return (EXIT_FAILURE);
	if (ft_check_map(game.map) == FALSE)
		return (ft_free_map(game.map), 1);
	get_map_size(&game, game.map);
	if (is_valid_path(&game, av[1]) == FALSE)
		return (ft_free_map(game.map), 1);
	if (init_so_long(&game) == FALSE)
		return (EXIT_FAILURE);
	return (0);
}
