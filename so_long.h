/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relvan <relvan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:56:53 by relvan            #+#    #+#             */
/*   Updated: 2024/01/15 19:57:05 by relvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef PATHS_XPM
#  define COIN_P "xpm/starfruit.xpm"
#  define WALL_P "xpm/bush.xpm"
#  define RIGHT_P "xpm/seb_sag.xpm"
#  define LEFT_P "xpm/seb_sol.xpm"
#  define FRONT_P "xpm/seb_on.xpm"
#  define BACK_P "xpm/seb_arka.xpm"
#  define EXIT_P "xpm/gate.xpm"
#  define FLOOR_P "xpm/floor.xpm"
# endif

enum e_key_codes
{
	KEY_A	= 0,
	KEY_S	= 1,
	KEY_D	= 2,
	KEY_W	= 13,
	KEY_ESC	= 53
};

typedef struct s_map
{
	char	**all_map;
	char	**copy_map;
	int		row_x;
	int		col_y;
	int		player_count;
	int		exit_count;
	int		collec_count;	
}				t_map;

typedef struct s_images
{
	void	*player;
	void	*front;
	void	*back;
	void	*right;
	void	*left;
	void	*exit;
	void	*coin;
	void	*wall;
	void	*floor;
}			t_images;

typedef struct s_game
{
	t_map		*map;
	t_images	img;
	void		*mlx;
	void		*win;
	int			loc_px;
	int			loc_py;
	int			loc_exit_x;
	int			loc_exit_y;
	int			step;
}				t_game;

int		ft_printf(const char *format, ...);
int		print_str(const char *str);
int		print_nbr(int nb);
int		print_char(int c);

int		ft_strlen(const char *str);
int		ft_chrcmp(char *str, int c);
char	*ft_strjoin(char *temp, char *buffer);
char	*get_next_line(int fd);
char	*add_temp(int fd, char *buffer, char *temp);
char	*get_after_line(char *temp);
char	*get_before_line(char *temp);
void	ft_putstr(char *str);

void	free_line(t_game *game, char **map);
void	ft_error(char *str);
int		finish_game(t_game *game);

void	ft_place(t_game *game);
void	put_place(t_game *game, char ch, int x, int y);
void	image_paths(t_game *game);
void	open_xpm(void);
void	fd_xpm(char *path_xpm);

int		map_line_count(char *path);
int		open_file_control(char *path);
int		ft_strchr(char *str, int c);
void	reachable_exit(t_game *game);

void	map_name(char *str);
void	component_check(t_map *map);
void	read_map(char *path, t_map *map);
void	copy_map(t_map *map, char *path);
void	is_line_equal(t_map *map);

void	wall_check(t_map *map);
void	min_component(t_map *map);
void	total_check(t_game *game, char *path);

int		key_hook(int keycode, t_game *game);
void	change_player(int keyhook, t_game *game);
void	is_won_game(t_game *game, int x, int y);
void	play(t_game *game, int x, int y);

void	game_init(t_game *game);

void	flood_fill(t_game *game, int begin_x, int begin_y);
void	fill(t_game *game, int begin_x, int begin_y, char to_fill);
void	map_valid(t_game *game);
void	loc_player(t_game *game);
void	is_reachable(char **map);
void	loc_exit(t_game *game);

#endif