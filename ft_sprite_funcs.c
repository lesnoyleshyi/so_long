/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:57:57 by stycho            #+#    #+#             */
/*   Updated: 2021/12/14 21:57:59 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_sprites(t_data *data)
{
	data->empty_sp = ft_get_sprite(data, "./sprites/background.xpm");
	data->wall = ft_get_sprite(data, "./sprites/wall.xpm");
	data->collectible = ft_get_sprite(data, "./sprites/coin.xpm");
	data->exit = ft_get_sprite(data, "./sprites/closed_exit.xpm");
	data->open_exit = ft_get_sprite(data, "./sprites/open_exit.xpm");
	data->enemy = ft_get_sprite(data, "./sprites/enemy.xpm");
	data->hero_up[0] = ft_get_sprite(data, "./sprites/player_up_0.xpm");
	data->hero_up[1] = ft_get_sprite(data, "./sprites/player_up_1.xpm");
	data->hero_down[0] = ft_get_sprite(data, "./sprites/player_down_0.xpm");
	data->hero_down[1] = ft_get_sprite(data, "./sprites/player_down_1.xpm");
	data->hero_right[0] = ft_get_sprite(data, "./sprites/player_right_0.xpm");
	data->hero_right[1] = ft_get_sprite(data, "./sprites/player_right_1.xpm");
	data->hero_left[0] = ft_get_sprite(data, "./sprites/player_left_0.xpm");
	data->hero_left[1] = ft_get_sprite(data, "./sprites/player_left_1.xpm");
	data->hero_orientation = data->hero_up;
	data->hero = data->hero_orientation[0];
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
