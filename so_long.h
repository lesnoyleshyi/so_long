/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:18:37 by stycho            #+#    #+#             */
/*   Updated: 2021/12/14 21:18:38 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFERSIZE 2
# include "mlx/mlx_mms/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_map {
	char	**strings;
	int		rows;
	int		cols;
	int		collectibles_count;
	int		pl_pos_x;
	int		pl_pos_y;
	int		player_steps;
}				t_map;

typedef struct s_img {
	void	*addr;
	int		x_dim;
	int		y_dim;
}				t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	*empty_sp;
	t_img	*wall;
	t_img	*collectible;
	t_img	*exit;
	t_img	*open_exit;
	t_img	*hero_up[2];
	t_img	*hero_down[2];
	t_img	*hero_right[2];
	t_img	*hero_left[2];
	t_img	**hero_orientation;
	t_img	*hero;
	t_img	*enemy;
	t_map	*map;
}				t_data;

t_map	*ft_get_map(const char *path_to_file);
int		ft_print_map(t_data *data);
t_img	*ft_get_sprite(t_data *data, char *path_to_image);
char	**ft_get_big_map(int fd, char *str);
char	**ft_read_map(const char *path_to_file);
void	ft_close_fd_and_exit(int fd, const char *msg);
void	ft_check_map_extension(const char *path_to_file);
void	ft_check_map_symbols(t_map *map);
void	ft_free_array(char **array, int str_count);
void	ft_perror_and_exit(const char *error_message);
void	ft_verify_symbols_count(int exits, int collectibles, int players);
void	ft_print_sprite(t_data *data, char sprite_symb, int x_pos, int y_pos);
void	ft_put_step_count_to_win(t_data *data);
void	ft_get_sprites(t_data *data);
void	ft_get_player_pos(t_map *map);
void	ft_check_is_enclosed(t_map map);
void	ft_check_rectangularity(t_map *map);
void	ft_change_sprite_state(t_data *data);
void	ft_print_steps_count(int steps_count);
void	ft_move_up(t_map *map, t_data *data);
void	ft_move_down(t_map *map, t_data *data);
void	ft_move_left(t_map *map, t_data *data);
void	ft_move_right(t_map *map, t_data *data);
int		ft_react_to_key(int keycode, t_data *data);
int		ft_react_to_close_win(t_data *data);

#endif
