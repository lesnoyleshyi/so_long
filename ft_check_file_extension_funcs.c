/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:18:08 by stycho            #+#    #+#             */
/*   Updated: 2021/12/15 16:18:09 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_extension(const char *path_to_file)
{
	char	**path_parts;
	char	**name_parts;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path_parts = ft_split(path_to_file, '/');
	while (path_parts[i])
		i++;
	name_parts = ft_split(path_parts[i - 1], '.');
	while (name_parts[j])
		j++;
	if (ft_strncmp("ber", name_parts[j - 1], 4))
	{
		ft_free_array(path_parts, i - 1);
		ft_free_array(name_parts, j - 1);
		ft_perror_and_exit("Wrong file extension\n");
	}
	ft_free_array(path_parts, i - 1);
	ft_free_array(name_parts, j - 1);
}

void	ft_free_array(char **array, int str_count)
{
	while (str_count >= 0)
		free(array[str_count--]);
	free(array);
}

void	ft_perror_and_exit(const char *error_message)
{
	ft_putstr_fd(error_message, 1);
	ft_putstr_fd("\n", 1);
	exit(EXIT_FAILURE);
}
