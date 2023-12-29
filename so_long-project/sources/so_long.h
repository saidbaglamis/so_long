/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaglami <mbaglami@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 02:10:30 by mbaglami          #+#    #+#             */
/*   Updated: 2023/11/26 02:10:30 by mbaglami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

# define KEY_UP  			126
# define KEY_LEFT  			123	
# define KEY_RIGHT 			124
# define KEY_DOWN  			125

# define KEY_Q				12
# define KEY_ESC  			53

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define WALL_XPM			"assets/sprites/dungeon/wall.XPM"
# define FLOOR_XPM			"assets/sprites/dungeon/floor.XPM"
# define COINS_XPM			"assets/sprites/dungeon/collectable.XPM"
# define PLAYER_RIGHT_XPM	"assets/sprites/dungeon/player.XPM"
# define OPEN_EXIT_XPM		"assets/sprites/dungeon/exit-opened.XPM"
# define EXIT_CLOSED_XPM	"assets/sprites//dungeon/exit-closed.XPM"

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			coins_dup;
	int			exit;
	int			players;
	t_positon	player;
	t_positon	exit_p;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_right;
}	t_game;

void	ft_check_command_line_arguments(int argc, char **argv, t_game *game);
void	ft_init_map(t_game *game, char *argv);
char	*ft_strappend(char **s1, const char *s2);
void	ft_check_for_empty_line(char *map, t_game *game);
void	ft_init_vars(t_game *game);
void	ft_check_map(t_game *game);
void	ft_check_rows(t_game *game);
size_t	ft_strlen_line(const char *str);
void	ft_check_columns(t_game *game);
void	ft_count_map_parameters(t_game *game);
void	ft_verify_map_parameters(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);
int		ft_render_map(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_print_movements(t_game *game);
int		ft_handle_input(int keysym, t_game *game);
void	ft_player_move(t_game *game, int x, int y, int player_sprite);
int		ft_victory(t_game *game);
int		ft_error_msg(char *message, t_game *game);
int		ft_close_game(t_game *game);
void	ft_free_all_allocated_memory(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_map(t_game *game);
int		special_len(t_game *game, int j);

#endif
