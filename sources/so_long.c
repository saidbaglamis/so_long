/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:25:12 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/27 01:25:12 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	flood_fill(int row, int col, t_game *game, int **visited)
{
	if (!(row >= 0 && row < game->map.rows && col >= 0
			&& col < game->map.columns && game->map.full[row][col] != '1' 
		&& visited[row][col] == 0))
		return ;
	if (game->map.full[row][col] == 'C')
		game->map.coins_dup--;
	visited[row][col] = 1;
	flood_fill(row - 1, col, game, visited);
	flood_fill(row + 1, col, game, visited);
	flood_fill(row, col - 1, game, visited);
	flood_fill(row, col + 1, game, visited);
}

void	free_visited(int **visited)
{
	int	i;

	i = -1;
	while (visited[++i])
		free(visited[i]);
	free(visited);
}

void	ft_spot_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.full[y][x] == MAP_EXIT)
			{
				game->map.exit_p.x = x;
				game->map.exit_p.y = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_check_path(t_game *game)
{
	int	**visited;
	int	i;
	int	j;

	visited = malloc(game->map.rows * sizeof(int *));
	if (!visited)
		ft_error_msg("Allocation failed in check path", game);
	i = -1;
	while (++i < game->map.rows)
	{
		visited[i] = malloc(game->map.columns * sizeof(int));
		if (!visited[i])
			ft_error_msg("Allocation failed in check path", game);
		j = -1;
		while (++j < game->map.columns)
			visited[i][j] = 0;
	}
	flood_fill(game->map.player.y, game->map.player.x, game, visited);
	if (!(visited[game->map.exit_p.y][game->map.exit_p.x] == 1
		&& game->map.coins_dup == 0))
	{
		free_visited(visited);
		ft_error_msg("No valid path found!", game);
	}
	free_visited(visited);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_check_command_line_arguments(argc, argv, game);
	ft_init_map(game, argv[1]);
	ft_init_vars(game);
	ft_check_map(game);
	ft_spot_exit(game);
	ft_check_path(game);
	ft_init_mlx(game);
	ft_init_sprites(game);
	ft_render_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify, ButtonPressMask, ft_close_game,
		game);
	mlx_hook(game->win_ptr, Expose, ExposureMask, ft_render_map, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all_allocated_memory(game);
}
