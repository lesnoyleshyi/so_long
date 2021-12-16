/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_funcs_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:26:11 by stycho            #+#    #+#             */
/*   Updated: 2021/12/16 16:43:14 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_up(t_map *map, t_data *data)
{
	data->hero_orientation = data->hero_up;
	if (map->strings[map->pl_pos_x - 1][map->pl_pos_y] == 'G')
		exit(EXIT_SUCCESS);
	if ((map->strings[map->pl_pos_x - 1][map->pl_pos_y] == '1') ||
	((map->strings[map->pl_pos_x - 1][map->pl_pos_y] == 'E') &&
	map->collectibles_count != 0))
		return ;
	else
	{
		if (map->strings[map->pl_pos_x - 1][map->pl_pos_y] == 'C')
			map->collectibles_count -= 1;
		if (map->collectibles_count == 0)
		{
			data->exit->addr = data->open_exit->addr;
			if (map->strings[map->pl_pos_x - 1][map->pl_pos_y] == 'E')
				exit(EXIT_SUCCESS);
		}
		map->strings[map->pl_pos_x][map->pl_pos_y] = '0';
		map->strings[map->pl_pos_x - 1][map->pl_pos_y] = 'P';
		map->pl_pos_x -= 1;
		map->player_steps += 1;
		ft_print_steps_count(map->player_steps);
	}
}

void	ft_move_down(t_map *map, t_data *data)
{
	data->hero_orientation = data->hero_down;
	if (map->strings[map->pl_pos_x + 1][map->pl_pos_y] == 'G')
		exit(EXIT_SUCCESS);
	if ((map->strings[map->pl_pos_x + 1][map->pl_pos_y] == '1') ||
	((map->strings[map->pl_pos_x + 1][map->pl_pos_y] == 'E') &&
	map->collectibles_count != 0))
		return ;
	else
	{
		if (map->strings[map->pl_pos_x + 1][map->pl_pos_y] == 'C')
			map->collectibles_count -= 1;
		if (map->collectibles_count == 0)
		{
			data->exit->addr = data->open_exit->addr;
			if (map->strings[map->pl_pos_x + 1][map->pl_pos_y] == 'E')
				exit(EXIT_SUCCESS);
		}
		map->strings[map->pl_pos_x][map->pl_pos_y] = '0';
		map->strings[map->pl_pos_x + 1][map->pl_pos_y] = 'P';
		map->pl_pos_x += 1;
		map->player_steps += 1;
		ft_print_steps_count(map->player_steps);
	}
}

void	ft_move_left(t_map *map, t_data *data)
{
	data->hero_orientation = data->hero_left;
	if (map->strings[map->pl_pos_x][map->pl_pos_y - 1] == 'G')
		exit(EXIT_SUCCESS);
	if ((map->strings[map->pl_pos_x][map->pl_pos_y - 1] == '1') ||
	((map->strings[map->pl_pos_x][map->pl_pos_y - 1] == 'E') &&
	map->collectibles_count != 0))
		return ;
	else
	{
		if (map->strings[map->pl_pos_x][map->pl_pos_y - 1] == 'C')
			map->collectibles_count -= 1;
		if (map->collectibles_count == 0)
		{
			data->exit->addr = data->open_exit->addr;
			if (map->strings[map->pl_pos_x][map->pl_pos_y - 1] == 'E')
				exit(EXIT_SUCCESS);
		}
		map->strings[map->pl_pos_x][map->pl_pos_y] = '0';
		map->strings[map->pl_pos_x][map->pl_pos_y - 1] = 'P';
		map->pl_pos_y -= 1;
		map->player_steps += 1;
		ft_print_steps_count(map->player_steps);
	}
}

void	ft_move_right(t_map *map, t_data *data)
{
	data->hero_orientation = data->hero_right;
	if (map->strings[map->pl_pos_x][map->pl_pos_y + 1] == 'G')
		exit(EXIT_SUCCESS);
	if ((map->strings[map->pl_pos_x][map->pl_pos_y + 1] == '1') ||
	((map->strings[map->pl_pos_x][map->pl_pos_y + 1] == 'E') &&
	map->collectibles_count != 0))
		return ;
	else
	{
		if (map->strings[map->pl_pos_x][map->pl_pos_y + 1] == 'C')
			map->collectibles_count -= 1;
		if (map->collectibles_count == 0)
		{
			data->exit->addr = data->open_exit->addr;
			if (map->strings[map->pl_pos_x][map->pl_pos_y + 1] == 'E')
				exit(EXIT_SUCCESS);
		}
		map->strings[map->pl_pos_x][map->pl_pos_y] = '0';
		map->strings[map->pl_pos_x][map->pl_pos_y + 1] = 'P';
		map->pl_pos_y += 1;
		map->player_steps += 1;
		ft_print_steps_count(map->player_steps);
	}
}
