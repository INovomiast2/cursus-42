/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:05:34 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/15 13:10:44 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_so_long(t_solong *g)
{
	g->moves = 0;
	g->c_counter = 0;
	g->mlx = mlx_init(g->map_w, g->map_h, "so_long - By: ivnovomi", false);
	if (!(g->mlx))
		return (FALSE);
	ft_get_textures(g);
	ft_get_images(g);
	draw_map(g, g->imgs);
	mlx_key_hook(g->mlx, &ft_key, g);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	ft_free_map(g->map);
	free(g->txtrs);
	free(g->imgs);
	return (0);
}

int	main(int ac, char **av)
{
	t_solong	g;

	if (ac != 2)
		return (ft_printf(PARAMS_ERROR), 1);
	if (ft_file_extension(av[1]) == FALSE)
		return (ft_printf(MAP_EXT_ERROR));
	g.map = read_map(av[1]);
	if (!g.map)
		return (EXIT_FAILURE);
	if (ft_check_map(g.map) == FALSE)
		return (ft_free_map(g.map), 1);
	get_map_size(&g, g.map);
	if (is_valid_path(&g, av[1]) == FALSE)
		return (ft_free_map(g.map), 1);
	if (init_so_long(&g) == FALSE)
		return (EXIT_FAILURE);
	return (0);
}
