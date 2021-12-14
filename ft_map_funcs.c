/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:08:10 by stycho            #+#    #+#             */
/*   Updated: 2021/12/14 22:08:12 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "printf.h"

t_map	*ft_check_map(const char *path_to_file)
{
	int				fd;
	static t_map	map;
	char			raw_map[1001];
	int				ret;
	int				i;

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\nCan't open file with map\n", 32);
		exit(0);
	}
	ret = read(fd, &raw_map, 1000);
	if (ret == -1)
		exit(33);
	raw_map[ret] = '\0';
	map.strings = ft_split(raw_map, '\n');
	i = 0;
	printf("Map:\n");
	while (map.strings[i] != NULL)
	{
		printf("%d\t%s\n", i + 1, map.strings[i]);
		i++;
	}
	map.rows = i;
	map.cols = ft_strlen(map.strings[0]);
	ft_get_player_pos(&map);
	ft_count_collectibles(&map);
	map.player_steps = 0;
	printf("map.rows = %d\n", map.rows);
	printf("map.cols = %d\n", map.cols);
	printf("player start position: [%d][%d]\n", map.pl_pos_x, map.pl_pos_y);
	printf("Collectibles count: %d\n", map.collectibles_count);
	close(fd);
	return (&map);
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

void	ft_count_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->strings[i][j] == 'C' || map->strings[i][j] == 'c')
				map->collectibles_count++;
			j++;
		}
		i++;
	}
}
