/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 02:05:36 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/26 02:05:36 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>

void	ft_check_command_line_arguments(int argc, char **argv, t_game *game)
{
	int	map_parameter_len;

	game->map_alloc = false;
	if (argc > 2)
		ft_error_msg("Too many arguments (It should be only two).", game);
	if (argc < 2)
		ft_error_msg("The Map file is missing.", game);
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".ber", 4))
		ft_error_msg("Map file extention is wrong (It should be .ber).", game);
}

void	ft_init_map(t_game *game, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("The Map couldn't be opened. Does the Map exist?", game);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(map_temp, game);
	game->map.full = my_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}

void	ft_check_for_empty_2(char *map, int i, t_game *game)
{
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Invalid map. Empty line at the middle.", game);
		}
		i++;
	}
}

void	ft_check_for_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("Invalid map. Empty line right at the beginning.", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free (map);
		ft_error_msg("Invalid map. Empty line at the end.", game);
	}
	else if (map[0] == '\0')
	{
		free(map);
		ft_error_msg("Invalid map. The map is empty.", game);
	}
	ft_check_for_empty_2(map, i, game);
}