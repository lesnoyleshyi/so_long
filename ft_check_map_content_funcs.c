/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_content_funcs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:34:53 by stycho            #+#    #+#             */
/*   Updated: 2021/12/15 17:34:54 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_symbols(t_map *map)
{
	int			i;
	int			j;
	static int	exit_count;
	static int	players_count;

	i = 0;
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
			if (map->strings[i][j] == 'P' || map->strings[i][j] == 'p')
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
