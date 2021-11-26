/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:51:11 by stycho            #+#    #+#             */
/*   Updated: 2021/11/23 14:51:13 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_mms/mlx.h"
#include <stdio.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef struct	s_map	{
char	**strings;
int		rows;
int		cols;
int		pl_pos_x;
int		pl_pos_y;
}				t_map;

typedef struct	s_img	{
void	*addr;
int		x_dim;
int		y_dim;
}				t_img;

typedef	struct	s_data	{
void	*mlx;
void	*win;
t_img	*empty_sp;
t_img	*wall;
t_img	*collectible;
t_img	*exit;
t_img	*player;
t_img	*enemy;
t_map	*map;
}				t_data;


t_map	*ft_check_map(const char *path_to_file);
int		ft_print_map(t_data *data);
void	ft_print_sprite(t_data *data, char sprite_symb, int x_pos, int y_pos);
void	ft_get_sprites(t_data *data);
t_img	*ft_get_sprite(t_data *data, char *path_to_image);
int		ft_exit_prog(int keycode, t_data *data);
void	ft_get_player_pos(t_map *map);

int main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		write(1, "You should provide one map as the first argument\n", 50);
		return (0);
	}
	data.map = ft_check_map(argv[1]);
	data.mlx = mlx_init();
	ft_get_sprites(&data);
	data.win = mlx_new_window(data.mlx, (data.map->cols) * data.player->x_dim,
							  (data.map->rows) * data.player->y_dim, "so_long");
	ft_print_map(&data);
	mlx_hook(data.win, 2, 1L<<0, ft_exit_prog, &data);
	mlx_loop(data.mlx);
	return (0);
}

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
	printf("map.rows = %d\n", map.rows);
	printf("map.cols = %d\n", map.cols);
	printf("player pos: [%d][%d]\n", map.pl_pos_x, map.pl_pos_y);
	close(fd);
	return (&map);
}

int		ft_exit_prog(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int		ft_print_map(t_data *data)
{
	int i;
	int j;

	j = 0;
	while (j < data->map->rows)
	{
		i = 0;
		while (i < data->map->cols)
		{
			ft_print_sprite(data, data->map->strings[j][i], i, j);
			i++;
		}
		j++;
	}
	return (0);
}

void	ft_print_sprite(t_data *data, char sprite_symb, int x_pos, int y_pos)
{
	if (sprite_symb == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall->addr,
								x_pos * (data->wall->x_dim),
								y_pos * (data->wall->y_dim));
	if (sprite_symb == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->empty_sp->addr,
											x_pos * (data->empty_sp->x_dim),
											y_pos * (data->empty_sp->y_dim));
	if (sprite_symb == 'C' || sprite_symb == 'c')
		mlx_put_image_to_window(data->mlx, data->win, data->collectible->addr,
											x_pos * (data->collectible->x_dim),
											y_pos * (data->collectible->y_dim));
	if (sprite_symb == 'E' || sprite_symb == 'e')
		mlx_put_image_to_window(data->mlx, data->win, data->exit->addr,
											x_pos * (data->exit->x_dim),
											y_pos * (data->exit->y_dim));
	if (sprite_symb == 'P' || sprite_symb == 'p')
		mlx_put_image_to_window(data->mlx, data->win, data->player->addr,
											x_pos * (data->player->x_dim),
											y_pos * (data->player->y_dim));
	if (sprite_symb == 'G' || sprite_symb == 'g')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy->addr,
											x_pos * (data->enemy->x_dim),
											y_pos * (data->enemy->y_dim));
}

void	ft_get_sprites(t_data *data)
{
	data->empty_sp = ft_get_sprite(data, "./sprites/background.xpm");
	data->wall = ft_get_sprite(data, "./sprites/wall.xpm");
	data->collectible = ft_get_sprite(data, "./sprites/coin.xpm");
	data->exit = ft_get_sprite(data, "./sprites/exit.xpm");
	data->player = ft_get_sprite(data, "./sprites/hero.XPM");
	data->enemy = ft_get_sprite(data, "./sprites/enemy.xpm");
}

t_img	*ft_get_sprite(t_data *data, char *path_to_image)
{
	t_img	*sprite;

	sprite = (t_img *)malloc(sizeof(t_img));
	if (!sprite)
		exit(EXIT_FAILURE);
	sprite->addr = mlx_xpm_file_to_image(data->mlx, path_to_image,
										 &(sprite->x_dim), &(sprite->y_dim));
	if (sprite->addr == NULL)
		exit(EXIT_FAILURE);
	return (sprite);
}

void	ft_get_player_pos(t_map *map)
{
	int i;
	int j;

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