/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_enemy_bonus_funcs.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:41:34 by stycho            #+#    #+#             */
/*   Updated: 2021/12/16 16:41:35 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_create_enemy(t_map *map, int x_pos, int y_pos)
{
	map->enemy_count++;
	if (map->enemy_count > 5)
		ft_perror_and_exit("Error\nMaximum count of enemies is 5\n");
	map->enemy_pos_x[map->enemy_count - 1] = x_pos;
	map->enemy_pos_y[map->enemy_count - 1] = y_pos;
}
