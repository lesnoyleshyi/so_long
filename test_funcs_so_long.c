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

typedef struct s_data	{
void	*img;
char	*addr;
int		bits_per_pixel;
int		line_length;
int		endian;
}				t_data;

typedef struct s_vars	{
void	*mlx;
void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_vars *vars);
int		close_win(int keycode, t_vars *vars);
int		exit_loop(void *param);

int main(void)
{
	void	*mlx;
	void	*mlx_win;
//	t_vars	vars;
//	t_data	image;
//	t_data	image2;
	void	*image3;
	int		image3_width;
	int 	image3_height;
	t_vars	img3_vars;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "so_long game");
//	vars.mlx = mlx;
//	vars.win = mlx_win;
//	image.img = mlx_new_image(mlx, 640, 480);
//	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
//	my_mlx_pixel_put(&image, 320, 240, 0x00FF0000);
//	mlx_put_image_to_window(mlx, mlx_win, image.img, 0, 0);
//	mlx_key_hook(mlx_win, key_hook, &vars);
//	image2.img = mlx_new_image(mlx, 100, 100);
//	image2.addr = mlx_get_data_addr(image2.img, &image2.bits_per_pixel, &image2.line_length, &image2.endian);
//	mlx_loop_hook(mlx, render_some_shit, &image2);
	img3_vars.mlx = mlx;
	img3_vars.win = mlx_win;
	image3 = mlx_xpm_file_to_image(mlx, "./sprites/dildo.xpm", &image3_width, &image3_height);
	if (image3)
	{
		mlx_put_image_to_window(mlx, mlx_win, image3, 0, 0);
		mlx_string_put(mlx, mlx_win, 100, 100, 0x00FF00FF, "Ha-ha, benis :D");
//		mlx_loop_hook(mlx, exit_loop, NULL);
		mlx_hook(mlx_win, 2, 1L<<0, close_win, &img3_vars);
		mlx_loop(mlx);
	}
	else
	{
		ft_putstr_fd("Dildo hasn't been read :(\n", 27);
		mlx_destroy_window(mlx, mlx_win);
		free(mlx);
		return (0);
	}
	printf("Use!\n");
//	mlx_hook(mlx_win, 2, 1L<<0, close_win, &vars);
//	mlx_loop(mlx);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		key_hook(int keycode, t_vars *vars)
{
	ft_putnbr_fd(keycode, 1);
	ft_putchar_fd('\n', 1);
	if (vars->mlx == NULL)
		return (1);
	return (0);
}

int		close_win(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		write(1, "Game over, druzhok\n", 20);
		return (0);
	}
	return (1);
}

int	exit_loop(void *param)
{
	if (param)
		return (1);
	exit(0);
}
