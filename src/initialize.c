#include "../includes/so_long.h"

void	draw_tile(void *mlx, void *win, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
}

int	row_count(char *s)
{
	int		fd;
	int		row;
	char	*line;

	fd = open(s, O_RDONLY);
	row = 0;
	if (fd != -1)
	{
		while ((line = get_next_line(fd)) != NULL)
		{
			free(line);
			row++;
		}
		close(fd);
	}
	return (row);
}

void	parse_map(t_data *game, char *map_file, int *map_width, int *map_height)
{
	int		fd;
	char	*line;
	int		row;

	fd = open(map_file, O_RDONLY);
	*map_height = row_count(map_file);
	*map_width = 0;
	row = 0;
	game->map = malloc(*map_height * sizeof(char *));
	if (fd != -1)
	{
		while ((line = get_next_line(fd)))
		{
			line[strcspn(line, "\n")] = 0;
			game->map[row] = line;
			*map_width = fmax(strlen(line), *map_width);
			row++;
		}
		close(fd);
	}
	else
	{
		fprintf(stderr, "Failed to open map file\n");
		return ;
	}
}

void	draw_map(t_data *game, int map_width, int map_height)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_height)
	{
		x = 0;
		while (x < map_width)
		{
			if (game->map[y][x] == '1')
			{
				draw_tile(game->mlx, game->win, game->img_tile, x, y);
			}
			else if (game->map[y][x] == 'P')
			{
				draw_tile(game->mlx, game->win, game->img_character, x, y);
			}
			else if (game->map[y][x] == 'C')
			{
				draw_tile(game->mlx, game->win, game->img_collectable, x, y);
			}
			else if (game->map[y][x] == 'E')
			{
				draw_tile(game->mlx, game->win, game->img_exit, x, y);
			}
			x++;
		}
		y++;
	}
}

void	start_game(t_data *game, char *map_file, int map_width, int map_height)
{
	int img_height, img_width;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map_width * TILE_SIZE, map_height
			* TILE_SIZE, "so_long");
	game->img_tile = mlx_xpm_file_to_image(game->mlx, "./sprites/pinkTile.xpm",
			&img_width, &img_height);
	game->img_character = mlx_xpm_file_to_image(game->mlx,
			"./sprites/witchKitty.xpm", &img_width, &img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx,
			"./sprites/pinkCrystal.xpm", &img_width, &img_height);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./sprites/portal.xpm", &img_width, &img_height);
	draw_map(game, map_width, map_height);
	mlx_loop(game->mlx);
}
