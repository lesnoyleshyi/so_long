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

t_map	*ft_get_map(const char *path_to_file)
{
	static t_map	map;
	int				i;

	ft_check_map_extension(path_to_file);
	map.strings = ft_read_map(path_to_file);
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
	return (&map);
}

char	**ft_read_map(const char *path_to_file)
{
	int		fd;
	int		ret;
	char	**map;
	char	buf[BUFFERSIZE + 1];

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
		ft_close_fd_and_exit(fd, "Error!\nCan't open map\n");
	ret = read(fd, buf, BUFFERSIZE);
	if (ret == 0)
		ft_close_fd_and_exit(fd, "Error!\nEmpty file!\n");
	if (ret == -1)
		ft_close_fd_and_exit(fd, "Error!\nCan't read map\n");
	if (ret < BUFFERSIZE)
		map = ft_split(buf, '\n');
	else
		map = ft_get_big_map(fd, buf);
	close(fd);
	if (map == NULL)
		exit(EXIT_FAILURE);
	return (map);
}

char	**ft_get_big_map(int fd, char *str)
{
	char	**map;
	char	*res;
	char	*dummy_ptr;
	char	buf[BUFFERSIZE + 1];
	int		ret;

	res = ft_strdup(str);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFERSIZE);
		if (ret == -1)
			ft_close_fd_and_exit(fd, "read goes wrong while reading map \n");
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		dummy_ptr = res;
		if (!res)
			ft_close_fd_and_exit(fd, "strdup goes wrong while reading map\n");
		res = ft_strjoin(res, buf);
		free(dummy_ptr);
	}
	map = ft_split(res, '\n');
	free(res);
	return (map);
}

void	ft_close_fd_and_exit(int fd, const char *msg)
{
	close(fd);
	ft_putstr_fd(msg, 1);
	exit(EXIT_FAILURE);
}
