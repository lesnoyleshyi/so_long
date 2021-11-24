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
#define	SPRITE_SIZE 60

typedef	struct	s_data	{
void	*mlx;
void	*win;
void	*img;
}				t_data;

typedef struct	s_map	{
char	*strings;
int		rows;
int		cols;
}				t_map;

t_map	ft_check_map(const char *path_to_file);
int		ft_exit_prog(int keycode, t_data *data, void *param);
int		ft_update_frame(t_data *data, t_map *map);

int main(int argc, char *argv[])
{
	t_data	data;
	t_map	map;
	int	sprite_x_dim;
	int	sprite_y_dim;

	if (argc != 2)
	{
		write(1, "You should provide one map as the first argument\n", 50);
		return (0);
	}
	map = ft_check_map(argv[1]);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, map.cols * SPRITE_SIZE, map.rows * SPRITE_SIZE, "omg_so_long_daddy");
	data.img = mlx_xpm_file_to_image(data.mlx, "./sprites/my_hero.xpm", &sprite_x_dim, &sprite_y_dim);
//	data.img = mlx_new_image(data.mlx, map.cols * SPRITE_SIZE, map.rows * SPRITE_SIZE);
	mlx_loop_hook(data.mlx, ft_update_frame, &data);
	mlx_hook(data.win, 2, 1L<<0, ft_exit_prog, NULL);
	mlx_loop(data.mlx);
	return (0);
}

t_map	ft_check_map(const char *path_to_file)
{
	int		fd;
	t_map	map;

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\nCan't open file with map\n", 32);
		exit(0);
	}
	map.rows = 5;
	map.cols = 13;
	map.strings = "001PE00C";
	close(fd);
	return (map);
}

int		ft_exit_prog(int keycode, t_data *data, void *param)
{
	if (keycode == 53)
	{
		param = NULL;
//		mlx_destroy_window(data->mlx, data->win);
		free(data->win);
		free(data->mlx);
		exit(0);
	}
	return (0);
}

int		ft_update_frame(t_data *data, t_map *map)
{
	int	sprite_x_dim;
	int	sprite_y_dim;
	void *spr;

	spr = mlx_xpm_file_to_image(data->mlx, "./sprites/my_hero.xpm", &sprite_x_dim, &sprite_y_dim);
	if (!spr)
		exit(25);
//	mlx_put_image_to_window(data->mlx, data->win, spr, 0, 0);
//	mlx_put_image_to_window(data->mlx, data->win, spr, sprite_x_dim, 0);

	mlx_put_image_to_window(data->mlx, data->win, spr, (map->cols), (map->rows));
	printf("%d\n%d\n", map->cols, map->rows);
//  тут мапа не передаётся, надо её в структуру запихурить

//	while (map->cols != 0)
//	{
//		mlx_put_image_to_window(data->mlx, data->win, spr, (map->cols) * sprite_x_dim, (map->rows) * sprite_y_dim);
//		(map->cols)--;
//	}

	printf("hello\n");
//	if (map->cols == 0)
//		return (1);
	return (0);
}