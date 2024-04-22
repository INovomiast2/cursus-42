/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivnovomi <ivnovomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:26:35 by ivnovomi          #+#    #+#             */
/*   Updated: 2024/04/15 14:13:36 by ivnovomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	total_coins(t_solong *g)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'C')
				total++;
			j++;
		}
		i++;
	}
	return (total);
}

void	ft_delete(t_solong *g)
{
	int	i;
	int	counter;

	i = 0;
	counter = g->n_c;
	while (i < counter)
	{
		if ((g->imgs->coin->instances[i].y == g->imgs->plyr->instances->y)
			&& (g->imgs->coin->instances[i].x == g->imgs->plyr->instances->x)
			&& (g->imgs->coin->instances[i].enabled == true))
		{
			counter--;
			g->imgs->coin->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	ft_exit(t_solong *g)
{
	if (g->imgs->exit->instances->enabled == false
		&& g->imgs->exit->instances->x
		/ 32 == g->imgs->plyr->instances->x / 32
		&& g->imgs->exit->instances->y
		/ 32 == g->imgs->plyr->instances->y / 32)
	{
		ft_printf("Has ganado el juego con %i movimientos!\n", g->moves);
		mlx_close_window(g->mlx);
	}
}

void	ft_collect(t_solong *g)
{
	int	i;
	int	counter;

	i = 0;
	counter = g->n_c;
	while (i < counter)
	{
		if (((g->imgs->coin->instances[i].y
					/ 32 == g->imgs->plyr->instances->y / 32)
				&& (g->imgs->coin->instances[i].x
					/ 32 == g->imgs->plyr->instances->x / 32))
			&& g->imgs->coin->instances[i].enabled == true)
		{
			counter--;
			g->imgs->coin->instances[i].enabled = false;
			g->map[g->imgs->plyr->instances->y
				/ 32][g->imgs->plyr->instances->x / 32] = FLOOR;
			g->c_counter++;
			if (g->c_counter == g->n_c)
				g->imgs->exit->instances->enabled = false;
			return ;
		}
		i++;
	}
}
