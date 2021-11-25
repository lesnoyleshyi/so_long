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
}				t_map;

typedef struct	s_img	{
void	*addr;
int		x_dim;
int		y_dim;
}				t_img;

typedef	struct	s_data	{
void	*mlx;
void	*win;
t_img	*empty_space;
t_img	*wall;
t_img	*collectible;
t_img	*exit;
t_img	*player;
t_img	*enemy;
t_map	*map;
}				t_data;


t_map	*ft_check_map(const char *path_to_file);
int		ft_print_map(t_data *data);
int		ft_exit_prog(int keycode, t_data *data);
//int		ft_update_frame(t_data *data);

int main(int argc, char *argv[])
{
	t_data	data;
	int		x_dim;
	int		y_dim;
	t_img	*player;
	t_img	*back;

	if (argc != 2)
	{
		write(1, "You should provide one map as the first argument\n", 50);
		return (0);
	}
	data.map = ft_check_map(argv[1]);
	data.mlx = mlx_init();
	player = (t_img *)malloc(sizeof(t_img));
	back = (t_img *)malloc(sizeof(t_img));
	player->addr = mlx_xpm_file_to_image(data.mlx, "./sprites/my_hero.XPM", &x_dim, &y_dim);
//	data.empty_space->addr = mlx_xpm_file_to_image(data.mlx, "./sprites/background.xpm", &x_dim, &y_dim);
//	data.empty_space->x_dim = x_dim;
//	data.empty_space->y_dim = y_dim;
//	data.player = mlx_xpm_file_to_image(data.mlx, "./sprites/my_hero.XPM", &x_dim, &y_dim);
//	data.player->x_dim = x_dim;
//	data.player->y_dim = y_dim;

	data.player = player;
	data.win = mlx_new_window(data.mlx, (data.map->cols) * x_dim, (data.map->rows) * y_dim, "omg_so_long_daddy");
	printf("main: %p\n", data.player->addr);
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
	printf("map.rows = %d\n", map.rows);
	printf("map.cols = %d\n", map.cols);
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

//int		ft_update_frame(t_data *data)
//{
//	int	sprite_x_dim;
//	int	sprite_y_dim;
//	void *spr;
//
//	spr = mlx_xpm_file_to_image(data->mlx, "./sprites/my_hero.xpm", &sprite_x_dim, &sprite_y_dim);
//	if (!spr)
//		exit(25);
//	mlx_put_image_to_window(data->mlx, data->win, spr, data->map.cols, data->map.rows);
//	printf("%d\n%d\n", data->map.cols, data->map.rows);
//
//	while (data->map->cols >= 0)
//	{
//		mlx_put_image_to_window(data->mlx, data->win, spr, (data->map->cols) * sprite_x_dim, 0);
//		(data->map->cols)--;
//		printf("x_dim: %d\ny_dim: %d\nmap.cols: %d\nmap.rows: %d\n", sprite_x_dim, sprite_y_dim, data->map->cols, data->map->rows);
//	}
//
//	printf("hello\n");
//	if (map->cols == 0)
//		return (1);
//	return (0);
//}

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
//			printf("ft_print_map: %p ", data->player->addr);
			mlx_put_image_to_window(data->mlx, data->win, data->player->addr, i * 63, j * 63);
//			printf("%d:%d ", i, j);
			i++;
		}
		printf("\n");
		j++;
	}
	return (0);
}