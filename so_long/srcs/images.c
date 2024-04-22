/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:04:10 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/15 13:15:51 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_get_textures(t_solong *g)
{
	g->txtrs = ft_calloc(1, sizeof(t_textures));
	g->txtrs->floor = mlx_load_png("assets/textures/enviroment/grass32x32.png");
	g->txtrs->wall = mlx_load_png("assets/textures/enviroment/wall_32x32.png");
	g->txtrs->coin = mlx_load_png("assets/textures/collectible/coin_32x32.png");
	g->txtrs->plyr = mlx_load_png("assets/textures/character/char_32x32.png");
	g->txtrs->e_close = mlx_load_png("assets/textures/exit_closed_32x32.png");
	g->txtrs->e_open = mlx_load_png("assets/textures/exit_open_32x32.png");
}

void	ft_get_images(t_solong *g)
{
	g->imgs = ft_calloc(1, sizeof(t_images));
	g->imgs->floor = mlx_texture_to_image(g->mlx, g->txtrs->floor);
	g->imgs->wall = mlx_texture_to_image(g->mlx, g->txtrs->wall);
	g->imgs->coin = mlx_texture_to_image(g->mlx,
			g->txtrs->coin);
	g->imgs->plyr = mlx_texture_to_image(g->mlx, g->txtrs->plyr);
	g->imgs->exit = mlx_texture_to_image(g->mlx,
			g->txtrs->e_close);
	g->imgs->second_exit = mlx_texture_to_image(g->mlx,
			g->txtrs->e_open);
	mlx_delete_texture(g->txtrs->floor);
	mlx_delete_texture(g->txtrs->wall);
	mlx_delete_texture(g->txtrs->coin);
	mlx_delete_texture(g->txtrs->plyr);
	mlx_delete_texture(g->txtrs->e_close);
	mlx_delete_texture(g->txtrs->e_open);
}

void	ft_draw_floor(t_solong *g, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			mlx_image_to_window(g->mlx, image->floor, x * 32, y * 32);
			if (g->map[y][x] == WALL)
				mlx_image_to_window(g->mlx, image->wall, x * 32, y * 32);
			if (g->map[y][x] == EXIT)
			{
				mlx_image_to_window(g->mlx, image->second_exit, x * 32, y
					* 32);
				mlx_image_to_window(g->mlx, image->exit, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

void	draw_map(t_solong *g, t_images *image)
{
	int	x;
	int	y;

	ft_draw_floor(g, image);
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == COLLECTIBLE)
				mlx_image_to_window(g->mlx, image->coin, x * 32, y
					* 32);
			if (g->map[y][x] == PLAYER_START)
				mlx_image_to_window(g->mlx, image->plyr, x * 32, y
					* 32);
			x++;
		}
		y++;
	}
}
