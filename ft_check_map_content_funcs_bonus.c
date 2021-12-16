/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_content_funcs_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:34:53 by stycho            #+#    #+#             */
/*   Updated: 2021/12/16 16:38:57 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_map_symbols(t_map *map)
{
	static int	i;
	int			j;
	static int	exit_count;
	static int	players_count;

	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (!(ft_strchr("01CEPG", map->strings[i][j])))
				ft_perror_and_exit("Error\nInvalid symbol in map\n");
			if (map->strings[i][j] == 'E')
				exit_count++;
			if (map->strings[i][j] == 'C')
				map->collectibles_count++;
			if (map->strings[i][j] == 'P')
				players_count++;
			if (map->strings[i][j] == 'G')
				ft_create_enemy(map, i, j);
			j++;
		}
		i++;
	}
	ft_verify_symbols_count(exit_count, map->collectibles_count, players_count);
}

void	ft_verify_symbols_count(int exits, int collectibles, int players)
{
	if (exits == 0 || players != 1 || collectibles == 0)
		ft_perror_and_exit("Error\nWrong P/E/C number\n");
}

void	ft_check_rectangularity(t_map *map)
{
	int	i;

	i = 0;
	map->cols = ft_strlen(map->strings[0]);
	while (map->strings[i])
	{
		if (map->cols != (int)ft_strlen(map->strings[i]))
			ft_perror_and_exit("Error\nMap is not rectangular\n");
		i++;
	}
	map->rows = i;
}

void	ft_check_is_enclosed(t_map map)
{
	int	cols;
	int	rows;

	cols = map.cols;
	rows = map.rows;
	while (cols--)
	{
		if (map.strings[0][cols] != '1' || map.strings[rows - 1][cols] != '1')
			ft_perror_and_exit("Error\nMap is not enclosed\n");
	}
	cols = map.cols;
	while (rows--)
	{
		if (map.strings[rows][0] != '1' || map.strings[rows][cols -1] != '1')
			ft_perror_and_exit("Error\nMap is not enclosed\n");
	}
}

void	ft_get_player_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->strings[i][j] == 'P')
			{
				map->pl_pos_x = i;
				map->pl_pos_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
