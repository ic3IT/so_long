#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <math.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_tile;
	void	*img_character;
	void	*img_collectable;
	void	*img_background;
	void	*img_exit;
	void	*img_blackTile;
	int		collectables;
	int		all_collectables;
	void	*movements;
	char	**map;
	int		char_x;
	int		char_y;
	int		character_count;
	int 	exit_count;
}			t_data;

// game.collectables = 0;


# define WINDOW_WIDTH 960
# define WINDOW_HEIGHT 640
# define TILE_SIZE 64

char		*get_next_line(int fd);
int			ft_newline(char *s);
// MAPPING
void		draw_tile(void *mlx, void *win, void *img, int x, int y);
int			row_count(char *s);
void		parse_map(t_data *game, char *map_file, int *map_width,
				int *map_height);
void		start_game(t_data *game, int map_width,
				int map_height);
void		draw_map(t_data *game, int map_width, int map_height);
void	run_game(t_data *game, char *map_file);
void	update_graphics(int keysym, t_data *game, int x, int y);
int valid_move(int keysym, t_data *game, int x, int y);
int update_collectables(t_data *game);
int on_destroy(t_data *game);
int all_collectables_collected_exit(int keysym, t_data *game, int x, int y);
int valid_map(t_data *game, int *map_height);

#endif
