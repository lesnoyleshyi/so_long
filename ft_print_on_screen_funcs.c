/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_on_screen_funcs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:05:09 by stycho            #+#    #+#             */
/*   Updated: 2021/12/14 22:05:11 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_map(t_data *data)
{
	int	i;
	int	j;

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

void	ft_print_steps_count(int steps_count)
{
	char	*count;

	count = ft_itoa(steps_count);
	ft_putstr_fd("Players steps count: ", 1);
	ft_putstr_fd(count, 1);
	ft_putstr_fd("\n", 1);
	free(count);
}

void	ft_print_sprite(t_data *data, char sprite_symb, int x_pos, int y_pos)
{
	if (sprite_symb == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall->addr,
			x_pos * (data->wall->x_dim), y_pos * (data->wall->y_dim));
	if (sprite_symb == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->empty_sp->addr,
			x_pos * (data->empty_sp->x_dim), y_pos * (data->empty_sp->y_dim));
	if (sprite_symb == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collectible->addr,
			x_pos * (data->collectible->x_dim),
			y_pos * (data->collectible->y_dim));
	if (sprite_symb == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit->addr,
			x_pos * (data->exit->x_dim), y_pos * (data->exit->y_dim));
	if (sprite_symb == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->hero->addr,
			x_pos * (data->hero->x_dim), y_pos * (data->hero->y_dim));
}
