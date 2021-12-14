/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_react_to_keys_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:32 by stycho            #+#    #+#             */
/*   Updated: 2021/12/14 21:54:34 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_react_to_key(int keycode, t_data *data)
{
	if (keycode == 13)
		ft_move_up(data->map, data);
	if (keycode == 1)
		ft_move_down(data->map, data);
	if (keycode == 0)
		ft_move_left(data->map, data);
	if (keycode == 2)
		ft_move_right(data->map, data);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
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

int	ft_react_to_close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
