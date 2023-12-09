#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_tile;
	void	*img_character;
	void	*img_collectable;
	void	*img_background;
	void	*img_exit;
	char	**map;
}			t_data;

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
void		start_game(t_data *game, char *map_file, int map_width,
				int map_height);
void		draw_map(t_data *game, int map_width, int map_height);

#endif
