void	ft_move_up(t_map *map)
{
	printf("Previous pos: [%d][%d]\n", map->pl_pos_x, map->pl_pos_y);
	map->strings[map->pl_pos_x][map->pl_pos_y] = '0';
	map->strings[map->pl_pos_x - 1][map->pl_pos_y] = 'P';
	map->pl_pos_x -= 1;
	printf("Next pos: [%d][%d]\n", map->pl_pos_x, map->pl_pos_y);
}

void	ft_move_down(t_map *map)
{
	printf("Previous pos: [%d][%d]\n", map->pl_pos_x, map->pl_pos_y);
	map->strings[map->pl_pos_x][map->pl_pos_y] = '0';
	map->strings[map->pl_pos_x + 1][map->pl_pos_y] = 'P';
	map->pl_pos_x += 1;
	printf("Next pos: [%d][%d]\n", map->pl_pos_x, map->pl_pos_y);
}

void	ft_move_left(t_map *map)
{
	printf("Previous pos: [%d][%d]\n", map->pl_pos_x, map->pl_pos_y);
	map->strings[map->pl_pos_x][map->pl_pos_y] = '0';
	map->strings[map->pl_pos_x][map->pl_pos_y - 1] = 'P';
	map->pl_pos_y -= 1;
	printf("Next pos: [%d][%d]\n", map->pl_pos_x, map->pl_pos_y);
}

void	ft_move_right(t_map *map)
{
	printf("Previous pos: [%d][%d]\n", map->pl_pos_x, map->pl_pos_y);
	map->strings[map->pl_pos_x][map->pl_pos_y] = '0';
	map->strings[map->pl_pos_x][map->pl_pos_y + 1] = 'P';
	map->pl_pos_y += 1;
	printf("Next pos: [%d][%d]\n", map->pl_pos_x, map->pl_pos_y);
}