/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_on_screen_funcs_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:05:09 by stycho            #+#    #+#             */
/*   Updated: 2021/12/16 16:43:46 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_print_map(t_data *data)
{
	int	i;
	int	j;

	ft_change_sprite_state(data);
	ft_change_enemies_pos(data);
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
	ft_put_step_count_to_win(data);
	return (0);
}

void	ft_change_sprite_state(t_data *data)
{
	static int	state;

	state += 1;
	if (state == 20)
		state = 0;
	if (state < 10)
		data->hero = data->hero_orientation[0];
	else
		data->hero = data->hero_orientation[1];
}

void	ft_change_enemies_pos(t_data *data)
{
	static int	counter;

	counter += 1;
	if (counter == 10)
	{
		ft_move_enemy(data->map, data);
		counter = 0;
	}
}

void	ft_put_step_count_to_win(t_data *data)
{
	char	*steps;
	int		color;

	color = 0x00FFFFFF;
	steps = ft_itoa(data->map->player_steps);
	mlx_string_put(data->mlx, data->win,
		(data->map->cols) / 2 * data->wall->x_dim,
		data->wall->y_dim / 2, color, "STEPS:");
	mlx_string_put(data->mlx, data->win,
		(data->map->cols) / 2 * data->wall->x_dim + 60,
		data->wall->y_dim / 2, color, steps);
	free(steps);
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
	if (sprite_symb == 'G')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy->addr,
			x_pos * (data->enemy->x_dim), y_pos * (data->enemy->y_dim));
}
