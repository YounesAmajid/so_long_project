/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:55:59 by yamajid           #+#    #+#             */
/*   Updated: 2023/06/01 16:21:20 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_right_move_function(t_player *player, t_map *map, char *line)
{
	int	i;

	i = player->x;
	if (line[i + 1] == 'C')
	{
		line[i + 1] = 'P';
		line[i] = '0';
		map->player->coins++;
		mlx_clear_window(map->game->mlx, map->game->win);
		ft_draw_map(map);
	}
	else if (line[i + 1] == '0')
	{
		line[i + 1] = 'P';
		line = ft_search_for_line(map, player->y);
		line[i] = '0';
		mlx_clear_window(map->game->mlx, map->game->win);
		ft_draw_map(map);
	}
}

int	ft_right_move(t_map *map)
{
	t_move	move;

	move.player = ft_get_player_loc(map);
	move.line = ft_search_for_line(map, move.player->y);
	if (move.line == NULL)
		return (free(move.player), 0);
	move.i = move.player->x;
	if (move.line[move.i + 1] == '1')
		return (free(move.player), 0);
	else if (move.line[move.i + 1] == 'C' || move.line[move.i + 1] == '0')
		help_right_move_function(move.player, map, move.line);
	if (move.line[move.i + 1] == 'E')
	{
		if (move.player->coins == move.player->coins_count)
			return (free(move.player), ft_win(map), 0);
		else
			return (free(move.player), 0);
	}
	ft_putnbr(map->player->moves++);
	write(1, "\n", 1);
	return (free(move.player), 0);
}
