/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:44:20 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/15 13:21:42 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_solong *g)
{
	if (g->map[g->imgs->plyr->instances->y / 32 - 1]
		[g->imgs->plyr->instances->x / 32] != WALL)
	{
		g->imgs->plyr->instances->y -= MOVE;
		g->moves++;
		ft_printf("Move: %i\n", g->moves);
	}
}

void	ft_move_down(t_solong *g)
{
	if (g->map[g->imgs->plyr->instances->y / 32 + 1]
		[g->imgs->plyr->instances->x / 32] != WALL)
	{
		g->imgs->plyr->instances->y += MOVE;
		g->moves++;
		ft_printf("Move: %i\n", g->moves);
	}
}

void	ft_move_left(t_solong *g)
{
	if (g->map[g->imgs->plyr->instances->y / 32]
		[g->imgs->plyr->instances->x / 32 - 1] != WALL)
	{
		g->imgs->plyr->instances->x -= MOVE;
		g->moves++;
		ft_printf("Move: %i\n", g->moves);
	}
}

void	ft_move_right(t_solong *g)
{
	if (g->map[g->imgs->plyr->instances->y / 32]
		[g->imgs->plyr->instances->x / 32 + 1] != WALL)
	{
		g->imgs->plyr->instances->x += MOVE;
		g->moves++;
		ft_printf("Moves: %i\n", g->moves);
	}
}

void	ft_key(mlx_key_data_t keydata, void *param)
{
	t_solong	*g;

	g = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		ft_move_up(g);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ft_move_down(g);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		ft_move_left(g);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		ft_move_right(g);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_close_window(g->mlx);
		ft_printf("\n😔\033[31m-[CERRASTE EL JUEGO]-\033[0m😔");
		return ;
	}
	ft_collect(g);
	ft_exit(g);
}
