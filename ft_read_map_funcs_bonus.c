/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_funcs_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:08:10 by stycho            #+#    #+#             */
/*   Updated: 2021/12/16 16:46:05 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map	*ft_get_map(const char *path_to_file)
{
	static t_map	map;

	ft_check_map_extension(path_to_file);
	map.strings = ft_read_map(path_to_file);
	ft_check_rectangularity(&map);
	ft_check_map_symbols(&map);
	ft_check_is_enclosed(map);
	ft_get_player_pos(&map);
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
