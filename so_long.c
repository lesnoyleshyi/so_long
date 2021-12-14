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

#include "so_long.h"

int	main(int argc, char *argv[])
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
	data.win = mlx_new_window(data.mlx, (data.map->cols) * data.wall->x_dim,
			(data.map->rows) * data.wall->y_dim, "so_long");
	mlx_loop_hook(data.mlx, ft_print_map, &data);
	mlx_hook(data.win, 17, 0L, ft_react_to_close_win, &data);
	mlx_hook(data.win, 2, 1L << 0, ft_react_to_key, &data);
	mlx_loop(data.mlx);
	return (0);
}
