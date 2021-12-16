/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemies_funcs_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:21:20 by stycho            #+#    #+#             */
/*   Updated: 2021/12/16 16:21:22 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_enemy(t_map *map, t_data *data)
{
	int	step_direction;

	step_direction = rand();
	if (step_direction % 4 == 0)
		ft_move_enemy_up(map, data);
	if (step_direction % 4 == 1)
		ft_move_enemy_down(map, data);
	if (step_direction % 4 == 2)
		ft_move_enemy_right(map, data);
	if (step_direction % 4 == 3)
		ft_move_enemy_left(map, data);
}

void	ft_move_enemy_up(t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (i < map->enemy_count)
	{
		if (map->strings[map->enemy_pos_x[i] - 1][map->enemy_pos_y[i]] == 'P')
			ft_react_to_close_win(data);
		if (map->strings[map->enemy_pos_x[i] - 1][map->enemy_pos_y[i]] == '0')
		{
			map->strings[map->enemy_pos_x[i] - 1][map->enemy_pos_y[i]] = 'G';
			map->strings[map->enemy_pos_x[i]][map->enemy_pos_y[i]] = '0';
			map->enemy_pos_x[i] -= 1;
		}
		i++;
	}
}

void	ft_move_enemy_down(t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (i < map->enemy_count)
	{
		if (map->strings[map->enemy_pos_x[i] + 1][map->enemy_pos_y[i]] == 'P')
			ft_react_to_close_win(data);
		if (map->strings[map->enemy_pos_x[i] + 1][map->enemy_pos_y[i]] == '0')
		{
			map->strings[map->enemy_pos_x[i] + 1][map->enemy_pos_y[i]] = 'G';
			map->strings[map->enemy_pos_x[i]][map->enemy_pos_y[i]] = '0';
			map->enemy_pos_x[i] += 1;
		}
		i++;
	}
}

void	ft_move_enemy_right(t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (i < map->enemy_count)
	{
		if (map->strings[map->enemy_pos_x[i]][map->enemy_pos_y[i] - 1] == 'P')
			ft_react_to_close_win(data);
		if (map->strings[map->enemy_pos_x[i]][map->enemy_pos_y[i] - 1] == '0')
		{
			map->strings[map->enemy_pos_x[i]][map->enemy_pos_y[i] - 1] = 'G';
			map->strings[map->enemy_pos_x[i]][map->enemy_pos_y[i]] = '0';
			map->enemy_pos_y[i] -= 1;
		}
		i++;
	}
}

void	ft_move_enemy_left(t_map *map, t_data *data)
{
	int	i;

	i = 0;
	while (i < map->enemy_count)
	{
		if (map->strings[map->enemy_pos_x[i]][map->enemy_pos_y[i] + 1] == 'P')
			ft_react_to_close_win(data);
		if (map->strings[map->enemy_pos_x[i]][map->enemy_pos_y[i] + 1] == '0')
		{
			map->strings[map->enemy_pos_x[i]][map->enemy_pos_y[i] + 1] = 'G';
			map->strings[map->enemy_pos_x[i]][map->enemy_pos_y[i]] = '0';
			map->enemy_pos_y[i] += 1;
		}
		i++;
	}
}
