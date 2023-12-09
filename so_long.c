#include "so_long.h"

void draw_tile(void *mlx, void *win, void *img, int x, int y) {
    mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y * TILE_SIZE);
}

typedef struct s_data {
	void *mlx;
    void *win;
    void *img_tile;
	void *img_background;
	char **map;
} t_data;

int row_count(char *s) {
    int fd = open(s, O_RDONLY);
    int row = 0;
    char *line;
    if (fd != -1 ) {
    while ((line = get_next_line(fd)) != NULL) {
        free(line);
        row++;
    }
    close(fd);
    }
    return row;
}

void parse_map(t_data *game, char *map_file) {
    int fd = open(map_file, O_RDONLY);
    char *line;
    int line_count = row_count(map_file);
    int row = 0;

    game->map = malloc(line_count * sizeof(char *));


    if (fd != -1) {
        while (line = get_next_line(fd)) {
            game->map[row++] = line;
        }
        game->map[row] = NULL;
        close(fd);
    }  else {
        return;
    }
}

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	t_data game;
	int img_height, img_width;
    int num_horizontal_tiles = WINDOW_WIDTH / TILE_SIZE;
    int num_vertical_tiles = WINDOW_HEIGHT / TILE_SIZE;

    if (argc == 2) {
        parse_map(&game, argv[1]);
        size_t i = 0;
        while (game.map[i]) {
            printf("%s", game.map[i]);
            i++;
        }
    


    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
    game.img_tile = mlx_xpm_file_to_image(game.mlx, "./sprites/Tile_12.xpm", &img_width, &img_height);

    int y = 0;
    while (y < num_vertical_tiles && game.map[y] != NULL) {
    int x = 0;
    while (x < num_horizontal_tiles) {
        if (game.map[y][x] == '0') { // Example: '0' represents a floor tile
            draw_tile(game.mlx, game.win, game.img_tile, x, y);
        }
        // Add more conditions for other tile types
        x++;
    }
    y++;
}
    mlx_loop(game.mlx);
    } else {
        printf("type in map\n");
    }
    return 0;
}
